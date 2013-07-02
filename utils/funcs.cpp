// Declarations - belong in bitcoind_commands.h
result_t bitcoind_addmultisigaddress(bool bHelp, const params_t& params);
result_t bitcoind_addnode(bool bHelp, const params_t& params);
result_t bitcoind_backupwallet(bool bHelp, const params_t& params);
result_t bitcoind_createmultisig(bool bHelp, const params_t& params);
result_t bitcoind_getinfo(bool bHelp, const params_t& params);
result_t bitcoind_getblockcount(bool bHelp, const params_t& params);
result_t bitcoind_getbalance(bool bHelp, const params_t& params);

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
        return "getinfo  - Returns an object containing various state info.";
    }

    return exec_bitcoind("getinfo", params);
}

result_t bitcoind_getblockcount(bool bHelp, const params_t& params)
{
    if (bHelp ||  params.size() != 0 ) {
        return "getblockcount  - Returns the number of blocks in the longest block chain.";
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

// main function - belongs in bitshell.cpp
int main(int argc, char** argv)
{
    initCommands();
    addCommand("addmultisigaddress", &bitcoind_addmultisigaddress);
    addCommand("addnode", &bitcoind_addnode);
    addCommand("backupwallet", &bitcoind_backupwallet);
    addCommand("createmultisig", &bitcoind_createmultisig);
    addCommand("getinfo", &bitcoind_getinfo);
    addCommand("getblockcount", &bitcoind_getblockcount);
    addCommand("getbalance", &bitcoind_getbalance);
    return startInterpreter(argc, argv);
}
