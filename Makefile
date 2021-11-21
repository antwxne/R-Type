SHELL	=	/bin/sh
RM		?=	rm -f

## Output
SERVER_NAME			=	server
CLIENT_NAME		=	client
BUILD_DIR	=	build
DOC_DIR 	=	Documentation

## Rules ##
.PHONY: all
all:
	mkdir -p $(BUILD_DIR) && cd $(BUILD_DIR) && conan install .. --build=missing \
	&& cmake -DCMAKE_BUILD_TYPE=Release .. -G "Unix Makefiles" && cmake --build .

	cp ${BUILD_DIR}/bin/r-type_client . && mv ${BUILD_DIR}/bin/r-type_server .
	mkdir -p lib && cp ${BUILD_DIR}/lib/libGeldMonsterEntity.so ./lib && cp ${BUILD_DIR}/lib/libAccordeonMonsterEntity.so ./lib && cp ${BUILD_DIR}/lib/libCheetahMonsterEntity.so ./lib

.PHONY: debug
debug:
	mkdir -p $(BUILD_DIR) && cd $(BUILD_DIR) && conan install .. --build=missing\
	&& cmake -DCMAKE_BUILD_TYPE=Debug .. -G "Unix Makefiles" && cmake --build .

	cp ${BUILD_DIR}/bin/r-type_client . && mv ${BUILD_DIR}/bin/r-type_server .
	mkdir -p lib && cp ${BUILD_DIR}/lib/libGeldMonsterEntity.so ./lib && cp ${BUILD_DIR}/lib/libAccordeonMonsterEntity.so ./lib && cp ${BUILD_DIR}/lib/libCheetahMonsterEntity.so ./lib

# Clean build
.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

.PHONY: doc-clean
doc-clean:
	$(RM) -r $(DOC_DIR)/html/
	$(RM) -r $(DOC_DIR)/latex/
	$(RM) $(DOC_DIR)/refman.pdf

# Clean build and binaries
.PHONY: fclean
fclean: clean doc-clean

.PHONY: re
re: fclean all

.PHONY: tests_build
tests_build:
	mkdir -p $(BUILD_DIR) && cd $(BUILD_DIR) && conan install .. --build=missing \
    	&& cmake -DCMAKE_BUILD_TYPE=Release -DUNIT_TESTS=TRUE .. -G "Unix Makefiles" && cmake --build .

.PHONY: tests_run
tests_run: tests_build
	$(BUILD_DIR)/bin/unit_tests

.PHONY: doc
doc:
	doxygen $(DOC_DIR)/Doxyfile

# Generate PDF documentation
.PHONY: doc_pdf
doc-pdf:	doc
	make -C $(DOC_DIR)/latex/
	cp $(DOC_DIR)/latex/refman.pdf $(DOC_DIR)

# Launch doxygen in firefox browser
.PHONY: doc-firefox
doc-firefox:	doc
	firefox $(DOC_DIR)/html/index.html
