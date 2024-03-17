#include <string.h>

#include "postgres.h"

#if PG_VERSION_NUM >= 160000
#include "varatt.h"
#endif

#include "c.h"
#include "fmgr.h"

#include "soundex.h"

PG_MODULE_MAGIC;

/* Define the functions. */
PG_FUNCTION_INFO_V1(soundex_in);
PG_FUNCTION_INFO_V1(soundex_out);

/*
 * soundex_in
 *
 * Input from a CSTRING that we convert to our a Soundex, which gets
 * set a a Datum and returned.
 */
Datum soundex_in(PG_FUNCTION_ARGS) {
  /* The first argument as a CSTRING. */
  char *input = PG_GETARG_CSTRING(0);

  /* And get the length of the string. */
  int32 length = strlen(input);

  /*
   * Allocate enough memory for the output, we know a Soundex is 4 characters
   * plus a string termination character.
   */
  char *output = (char *)palloc(5);

  /* We just pass the output chat pointer in to the soundex function. */
  soundex(input, length, output);

  /* Free up any results we should be responsible for. */
  PG_FREE_IF_COPY(input, 0);

  /* Return a pointer to the output.  Postgres will pfree our memory. */
  PG_RETURN_POINTER(output);
}

/*
 * soundex_out
 *
 * Returns a CSTRING of the stored data.
 */
Datum soundex_out(PG_FUNCTION_ARGS) {
  /* Get a copy of the pointer from postgres. */
  char *input = PG_GETARG_POINTER(0);

  /* And simply return it. */
  PG_RETURN_CSTRING(input);
}
