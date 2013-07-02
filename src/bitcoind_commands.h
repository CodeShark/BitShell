///////////////////////////////////////////////////////////////////////////////
//
// bitcoind_commands.h
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

#ifndef BITCOIND_COMMANDS_H

#include <command_interpreter.h>

// Declarations - belong in bitcoind_commands.h
result_t bitcoind_addmultisigaddress(bool bHelp, const params_t& params);
result_t bitcoind_addnode(bool bHelp, const params_t& params);
result_t bitcoind_backupwallet(bool bHelp, const params_t& params);
result_t bitcoind_createmultisig(bool bHelp, const params_t& params);
result_t bitcoind_getinfo(bool bHelp, const params_t& params);
result_t bitcoind_getblock(bool bHelp, const params_t& params);
result_t bitcoind_getblockcount(bool bHelp, const params_t& params);
result_t bitcoind_getbalance(bool bHelp, const params_t& params);
result_t bitcoind_getnewaddress(bool bHelp, const params_t& params);
result_t bitcoind_getrawtransaction(bool bHelp, const params_t& params);
result_t bitcoind_getreceivedbyaccount(bool bHelp, const params_t& params);
result_t bitcoind_getreceivedbyaddress(bool bHelp, const params_t& params);
result_t bitcoind_listreceivedbyaddress(bool bHelp, const params_t& params);
result_t bitcoind_sendtoaddress(bool bHelp, const params_t& params);
result_t bitcoind_walletpassphrase(bool bHelp, const params_t& params);

#endif // BITCOIND_COMMANDS_H
