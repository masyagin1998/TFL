#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Simple library for searching russian postcodes in text.
"""

import argparse
import sys
import xml.etree.ElementTree as xml
from re import findall
from xml.dom.minidom import parseString


def find_postcodes(string: str) -> [str]:
    return findall(r'\b[1-46]\d{5}\b', string)


def dump_xml(postcodes: [str]) -> str:
    root = xml.Element("postcodes")
    for postcode in postcodes:
        num = xml.Element("num")
        num.text = postcode
        root.append(num)
    return parseString(xml.tostring(root)).toprettyxml(indent="\t")


def _errprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--input')
    parser.add_argument('--output')
    args = parser.parse_args()
    if args.input is None:
        _errprint('no input file was specified')
        sys.exit(1)
    if args.output is None:
        _errprint('no output file was specified')
        sys.exit(1)
    try:
        with open(args.input, 'r') as input_file, open(args.output, 'w') as output_file:
            output_file.write(dump_xml(find_postcodes(input_file.read())))
            print('OK')

    except IOError:
        _errprint('no such file or directory "%s"' % args.input)
        sys.exit(1)


if __name__ == "__main__":
    main()
