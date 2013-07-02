///////////////////////////////////////////////////////////////////////////////
//
// bitcoind_commands.cpp
//
// Copyright (c) 2013 Eric Lombrozo
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "bitcoind_commands.h"

#include <stdio.h>
#include <sstream>
#include <stdexcept>

#define BITCOIND_SHELL_CMD     "bitcoind"

using namespace std;

result_t exec_bitcoind(const string& method, const params_t& params)
{
    stringstream cmd;
    cmd << BITCOIND_SHELL_CMD << " " << method;
    for (size_t i = 0; i < params.size(); i++) {
        cmd << " " << params[i];
    }
    cmd << " 2>&1";    

    FILE* pipe = popen(cmd.str().c_str(), "r");
    if (!pipe) {
        throw runtime_error("Error opening pipe.");
    }

    char buffer[1025];
    stringstream out;
    while (!feof(pipe)) {
        if (fgets(buffer, 1024, pipe) != NULL) {
            out << buffer;
        }
    }

    if (pclose(pipe) == -1) {
        throw runtime_error("Error closing pipe.");
    }

    return out.str();
}

// Definitions - belong in bitcoind_commands.cpp
result_t bitcoind_addmultisigaddress(bool bHelp, const params_t& params)
{
    if (bHelp ||  params.size() < 2 || params.size() > 3 ) {
        return "addmultisigaddress <nrequired> <'[\"key\",\"key\"]'> [account] - Add a nrequired-to-sign multisignature address to the wallet";
    }

    return exec_bitcoind("addmultisigaddress", params);
}

result_t bitcoind_addnode(bool bHelp, const params_t& params)
{
    if (bHelp ||  params.size() != 2 ) {
        return "addnode <node> <add|remove|onetry> - Attempts add or remove <node> from the addnode list or try a connection to <node> once.";
    }

    return exec_bitcoind("addnode", params);
}

result_t bitcoind_backupwallet(bool bHelp, const params_t& params)
{
    if (bHelp ||  params.size() != 1 ) {
        return "backupwallet <destination> - Safely copies wallet.dat to destination, which can be a directory or a path with filename.";
    }

    return exec_bitcoind("backupwallet", params);
}

result_t bitcoind_createmultisig(bool bHelp, const params_t& params)
{
    if (bHelp ||  params.size() != 2 ) {
        return "createmultisig <nrequired> <'[\"key\",\"key\"]'> - Creates a multi-signature address and returns a json object.";
    }

    return exec_bitcoind("createmultisig", params);
}

result_t bitcoind_getinfo(bool bHelp, const params_t& params)
{
    if (bHelp ||  params.size() != 0 ) {
        return "getinfo - Returns an object containing various state info.";
    }

    return exec_bitcoind("getinfo", params);
}

result_t bitcoind_getblock(bool bHelp, const params_t& params)
{
    if (bHelp ||  params.size() < 1 || params.size() > 2 ) {
        return "getblock <hash> [verbose=true] - If verbose is false, returns a string that is serialized, hex-encoded data for block <hash>. If verbose is true, returns an Object with information about block <hash>.";
    }

    return exec_bitcoind("getblock", params);
}

result_t bitcoind_getblockcount(bool bHelp, const params_t& params)
{
    if (bHelp ||  params.size() != 0 ) {
        return "getblockcount - Returns the number of blocks in the longest block chain.";
    }

    return exec_bitcoind("getblockcount", params);
}

result_t bitcoind_getbalance(bool bHelp, const params_t& params)
{
    if (bHelp ||  params.size() < 0 || params.size() > 2 ) {
        return "getbalance [account] [minconf=1] - If [account] is not specified, returns the server's total available balance. If [account] is specified, returns the balance in the account.";
    }

    return exec_bitcoind("getbalance", params);
}

result_t bitcoind_getnewaddress(bool bHelp, const params_t& params)
{
    if (bHelp ||  params.size() < 0 || params.size() > 1 ) {
        return "getnewaddress [account] - Returns a new Bitcoin address for receiving payments.  If [account] is specified (recommended), it is added to the address book so payments received with the address will be credited to [account].";
    }

    return exec_bitcoind("getnewaddress", params);
}

result_t bitcoind_getrawtransaction(bool bHelp, const params_t& params)
{
    if (bHelp ||  params.size() < 1 || params.size() > 2 ) {
        return "getrawtransaction <txin> [verbose=0] - If verbose=0, returns a string that is serialized, hex-encoded data for <txid>. If verbose is non-zero, returns an Object with information about <txid>.";
    }

    return exec_bitcoind("getrawtransaction", params);
}

result_t bitcoind_getreceivedbyaccount(bool bHelp, const params_t& params)
{
    if (bHelp ||  params.size() < 1 || params.size() > 2 ) {
        return "getreceivedbyaccount <account> [minconf=1] - Returns the total amount received by addresses with <account> in transactions with at least [minconf] confirmations.";
    }

    return exec_bitcoind("getreceivedbyaccount", params);
}

result_t bitcoind_getreceivedbyaddress(bool bHelp, const params_t& params)
{
    if (bHelp ||  params.size() < 1 || params.size() > 2 ) {
        return "getreceivedbyaddress <bitcoinaddress> [minconf=1] - Returns the total amount received by <bitcoinaddress> in transactions with at least [minconf] confirmations.";
    }

    return exec_bitcoind("getreceivedbyaddress", params);
}

result_t bitcoind_listreceivedbyaddress(bool bHelp, const params_t& params)
{
    if (bHelp ||  params.size() < 0 || params.size() > 2 ) {
        return "listreceivedbyaddress [minconf=1] [includeempty=false] - [minconf] is the minimum number of confirmations before payments are included. [includeempty] whether to include addresses that haven't received any payments.";
    }

    return exec_bitcoind("listreceivedbyaddress", params);
}

result_t bitcoind_sendtoaddress(bool bHelp, const params_t& params)
{
    if (bHelp ||  params.size() < 2 || params.size() > 4 ) {
        return "sendtoaddress <bitcoinaddress> <amount> [comment] [comment-to] - <amount> is a real and is rounded to the nearest 0.00000001, requires wallet passphrase to be set with walletpassphrase first";
    }

    return exec_bitcoind("sendtoaddress", params);
}

result_t bitcoind_walletpassphrase(bool bHelp, const params_t& params)
{
    if (bHelp ||  params.size() != 2 ) {
        return "walletpassphrase <passphrase> <timeout> - Stores the wallet decryption key in memory for <timeout> seconds.";
    }

    return exec_bitcoind("walletpassphrase", params);
}

