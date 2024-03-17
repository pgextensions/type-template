OBJS = src/soundex.o src/type.o
MODULE_big = soundex-type

EXTENSION = soundex-type
DATA = soundex-type--1.0.0.sql
PGFILEDESC = "soundex - type"

REGRESS = soundex_type
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
