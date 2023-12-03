project('sim', 'c')

src = ['src/sim.c', 'src/world/tile.c', 'src/world/map_creation.c', 'src/objects/objects.c', 'src/objects/object.c', 'src/interface/interface.c', 'src/interface/canvas.c', 'src/interface/input.c']
incl = ['include']
deps = dependency('ncurses')
executable('sim', sources : src, dependencies : deps, include_directories : incl)
