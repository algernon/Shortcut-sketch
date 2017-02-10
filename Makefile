build:

setup:
	@sh -c '. ./.keyboardio-builder.conf && setup'

%:
	@lib/KeyboardioFirmware/tools/keyboardio-builder $@
