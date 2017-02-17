build:

setup:
	@sh -c '. ./.kaleidoscope-builder.conf && setup'

%:
	@hardware/keyboardio/avr/libraries/Kaleidoscope/tools/kaleidoscope-builder $@
