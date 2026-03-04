-include config.mk

ifndef CC
$(error config.mk not found. Run ./configure first)
endif

PROG = rps
SRCS = rps.c
LIBS = -lm

.PHONY: all install uninstall clean test

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS) $(LDFLAGS) $(LIBS)

install: $(PROG)
	install -d $(bindir)
	install -m 755 $(PROG) $(bindir)

uninstall:
	rm -f $(bindir)/$(PROG)

clean:
	rm -f $(PROG)

test: $(PROG)
	@echo "r" | ./$(PROG); \
	exit_code=$$?; \
	case $$exit_code in -1|0|1|255) exit 0 ;; *) exit 1 ;; esac
