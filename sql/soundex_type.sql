CREATE EXTENSION "soundex-type";

CREATE TABLE test_table (
  id INT,
  data soundex
);

INSERT INTO test_table VALUES (1, 'hello');
INSERT INTO test_table VALUES (2, 'world');

INSERT INTO test_table VALUES (3, 'john');
INSERT INTO test_table VALUES (4, 'joan');

SELECT * FROM test_table;

DROP TABLE test_table;
