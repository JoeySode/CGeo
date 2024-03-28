
# Changelog

## Version 1.0
## Release

Released

## Version 1.1
## Quads

### New Features

"cg_quad.h" and "cg_quad.c" have been added giving access to quadrilaterals that are not rectangles
The quad_t struct has 4 members: 'a', 'b', 'c', and 'd' which are all vec2s corresponding to the quad's vertices

### Fixes

Fixed bugs in the vec2's rotation functions causing incorrect outputs

### Formatting

All tabs are removes with 2 spaces
Slight adjustment to structure definition formats

### Inclusions

"cg_util.h" and "cg_def.h" are no longer included in "cgeo.h" but are still used by the library's internals
"cg_util.c" has been removed and the functions in "cg_util.h" have been replaced with macros
