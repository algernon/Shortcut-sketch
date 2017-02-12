build:

setup:
	@sh -c '. ./.kaleidoscope-builder.conf && setup'

%:
	@lib/Kaleidoscope/tools/kaleidoscope-builder $@
