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

.PHONY: debug
debug:
	mkdir -p $(BUILD_DIR) && cd $(BUILD_DIR) && conan install .. --build=missing\
	&& cmake -DCMAKE_BUILD_TYPE=Debug .. -G "Unix Makefiles" && cmake --build .

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
	$(RM) $(SERVER_NAME)
	$(RM) $(CLIENT_NAME)

.PHONY: re
re: fclean all

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
