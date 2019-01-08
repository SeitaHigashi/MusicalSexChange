objs = CLI.o Conversion.o Wav.o Interactive_CLI.o

CLI: $(objs)
	gcc -o MusicalSexChange $(objs)

CLI.o: CLI.c
	gcc -c CLI.c

CLI.o: CLI.h

Conversion.o: Conversion.c
	gcc -c Conversion.c

Conversion.o: Conversion.h

Wav.o: Wav.c
	gcc -c Wav.c

Wav.o: Wav.h

Interactive_CLI.o: Interactive_CLI.c
	gcc -c Interactive_CLI.c

Interactive_CLI.o: Interactive_CLI.h

clean:
	rm -rf $(objs) MusicalSexChange