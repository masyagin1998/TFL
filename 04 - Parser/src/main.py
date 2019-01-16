#!/usr/bin/env python3
import argparse
import os
import sys

from lexer.beautifier import beautify
from lexer.lexer import Lexer
from parser.parser import Parser
import parser.ast as ast

def errprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


desc_str = r"""JavaScript parser written with Ply."""


def parse_args():
    parser = argparse.ArgumentParser(prog='main',
                                     formatter_class=argparse.RawDescriptionHelpFormatter,
                                     description=desc_str)
    parser.add_argument('-v', '--version', action='version', version='%(prog)s v0.1')

    # Input.
    parser.add_argument('-i', '--input', type=str, default=os.path.join('.', 'test.js'),
                        help=r'test JavaScript file (default: "%(default)s")')

    # Options.
    parser.add_argument('-b', '--beautify', action='store_true',
                        help=r'beautify code before running lexer and parser')
    parser.add_argument('-l', '--lexer', action='store_true',
                        help=r'run lexer only'),
    parser.add_argument('-p', '--parser', action='store_true',
                        help=r'run parser')

    return parser.parse_args()


def visit(node, i):
    for child in node:
        t = ('\t' * i) + 'Node(' + type(child).__name__
        if isinstance(child, (ast.Identifier,
            ast.Boolean,
            ast.Null,
            ast.Number,
            ast.String,
            ast.Regex)):
            t += (', ' + child.value + ')')
            print(t)
            visit(child, i + 1)
        elif isinstance(child, (
            ast.BinOp,
            ast.Assign,
            ast.UnaryOp
        )):
            t += (', ' + child.op + ')')
            print(t)
            visit(child, i + 1)
        else:
            t += ')'
            print(t)
            visit(child, i + 1)


def main():
    args = parse_args()
    try:
        with open(args.input, 'r') as input_file:
            js_code = input_file.read()
            if args.beautify:
                js_code = beautify(js_code)
                print("Beautified code:")
                print(js_code)
            lexer = Lexer()
            lexer.input(js_code)
            if args.lexer:
                print("Lexer:")
                for token in lexer:
                    print(token)
            elif args.parser:
                parser = Parser()
                tree = parser.parse(js_code)
                print("Parser:")
                visit(tree, 0)

    except IOError:
        errprint('no such file or directory "%s"' % args.input)
        sys.exit(1)


if __name__ == "__main__":
    main()
