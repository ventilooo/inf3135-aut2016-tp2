############################################################################
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# 	Copyright [2016] [Pascal Vautour]
# 	Copyright [2016] [Nizar Semlali]
# 	Copyright [2016] [Istvan Szalai]
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#############################################################################

CC = gcc
CFLAGS = `pkg-config --cflags jansson`
LFLAGS = `pkg-config --libs jansson`
OBJECTS := $(patsubst %.c,%.o,$(wildcard src/*.c))
TEST_OBJECTS := $(patsubst %.c,%.o,$(wildcard test/*.c))
EXEC = bin/tp2
EXEC_TEST = test/suite

$(EXEC): $(OBJECTS)
	$(CC) $(LFLAGS) -o $(EXEC) $(OBJECTS) -ljansson

%.o: %.c
	$(CC) -Wall $(CFLAGS) -o $@ -c $<

.PHONY: clean data test

clean:
	rm -f $(EXEC) $(OBJECTS)
	rm -f $(EXEC_TEST) $(TEST_OBJECTS)

data:
	git submodule init
	git submodule update

test: $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $(EXEC_TEST) ./src/country.o $(TEST_OBJECTS) -ljansson -lcunit
	bats test/output.bats
