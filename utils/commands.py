#!/usr/bin/python

import sys

funcs = [
    {
        'name' : 'addmultisigaddress',
        'min' : 2,
        'max' : 3,
        'params' : '<nrequired> <\'[\\"key\\",\\"key\\"]\'> [account]',
        'help' : 'Add a nrequired-to-sign multisignature address to the wallet',
    },
    {
        'name' : 'addnode', 
        'min' : 2,
        'max' : 2,
        'params' : '<node> <add|remove|onetry>',
        'help' : 'Attempts add or remove <node> from the addnode list or try a connection to <node> once.',
    },
    {
        'name' : 'backupwallet',
        'min' : 1,
        'max' : 1,
        'params' : '<destination>',
        'help' : 'Safely copies wallet.dat to destination, which can be a directory or a path with filename.',
    },
    {
        'name' : 'createmultisig',
        'min' : 2,
        'max' : 2,
        'params' : '<nrequired> <\'[\\"key\\",\\"key\\"]\'>',
        'help' : 'Creates a multi-signature address and returns a json object.',
    },
    {
        'name' : 'getinfo',
        'min' : 0,
        'max' : 0,
        'params' : '',
        'help' : 'Returns an object containing various state info.',
    },
    {
        'name' : 'getblock',
        'min' : 1,
        'max' : 2,
        'params' : '<hash> [verbose=true]',
        'help' : 'If verbose is false, returns a string that is serialized, hex-encoded data for block <hash>. If verbose is true, returns an Object with information about block <hash>.',
    },
    {
        'name' : 'getblockcount',
        'min' : 0,
        'max' : 0,
        'params' : '',
        'help' : 'Returns the number of blocks in the longest block chain.'
    },
    {
        'name' : 'getbalance',
        'min' : 0,
        'max' : 2,
        'params' : '[account] [minconf=1]',
        'help' : 'If [account] is not specified, returns the server\'s total available balance. If [account] is specified, returns the balance in the account.',
    },
    {
        'name' : 'getrawtransaction',
        'min' : 1,
        'max' : 2,
        'params' : '<txin> [verbose=0]',
        'help' : 'If verbose=0, returns a string that is serialized, hex-encoded data for <txid>. If verbose is non-zero, returns an Object with information about <txid>.',
    },
    {
        'name' : 'getreceivedbyaccount',
        'min' : 1,
        'max' : 2,
        'params' : '<account> [minconf=1]',
        'help' : 'Returns the total amount received by addresses with <account> in transactions with at least [minconf] confirmations.',
    },
    {
        'name' : 'getreceivedbyaddress',
        'min' : 1,
        'max' : 2,
        'params' : '<bitcoinaddress> [minconf=1]',
        'help' : 'Returns the total amount received by <bitcoinaddress> in transactions with at least [minconf] confirmations.',
    },
]

if len(sys.argv) == 1 or sys.argv[1] == '--declarations':
    # declarations
    print '// Declarations - belong in bitcoind_commands.h'
    for func in funcs:
        print r'result_t bitcoind_%s(bool bHelp, const params_t& params);' % func['name']
    print

if len(sys.argv) == 1 or sys.argv[1] == '--definitions':
    # definitions
    print '// Definitions - belong in bitcoind_commands.cpp'
    for func in funcs:
        print r'result_t bitcoind_%s(bool bHelp, const params_t& params)' % func['name']
        print r'{'
        print r'    if (bHelp || ',
        if func['min'] == func['max']:
            print r'params.size() != %d' % func['min'],
        else:
            print r'params.size() < %d || params.size() > %d' % (func['min'], func['max']),

        print r') {'
        print r'        return "%s' % func['name'],
        if func['max'] > 0:
            print func['params'],
        print '- %s";' % func['help']
        print r'    }'
        print
        print r'    return exec_bitcoind("%s", params);' % func['name']
        print r'}'
        print

if len(sys.argv) == 1 or sys.argv[1] == '--main':
    # main function
    print '// main function - belongs in bitshell.cpp'
    print r'int main(int argc, char** argv)'
    print r'{'
    print r'    initCommands();'
    for func in funcs:
        print r'    addCommand("%s", &bitcoind_%s);' % (func['name'], func['name'])
    print r'    return startInterpreter(argc, argv);'
    print r'}'
