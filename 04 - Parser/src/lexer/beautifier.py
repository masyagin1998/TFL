import jsbeautifier


def beautify(string: str) -> str:
    opts = jsbeautifier.default_options()
    opts.indent_size = 4
    opts.preserve_newlines = False
    opts.indent_char = ' '
    opts.space_before_conditional = True
    opts.end_with_newline = True
    return jsbeautifier.beautify(string, opts)