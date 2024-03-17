
CREATE FUNCTION soundex_in(cstring)
  RETURNS soundex
  AS 'MODULE_PATHNAME', 'soundex_in'
  LANGUAGE C PARALLEL SAFE IMMUTABLE;

CREATE FUNCTION soundex_out(soundex)
  RETURNS cstring
  AS 'MODULE_PATHNAME', 'soundex_out'
  LANGUAGE C PARALLEL SAFE IMMUTABLE;

CREATE TYPE soundex (
  INTERNALLENGTH = 5,
  INPUT = soundex_in,
  OUTPUT = soundex_out
);