SHELL=/bin/bash
.ONESHELL:
.PHONY: compress clean

BUILD_DIR=build

build/portfolio.pdf: portfolio.tex
	mkdir $(BUILD_DIR) -p
	pdflatex -interaction=nonstopmode -halt-on-error -output-directory=$(BUILD_DIR) portfolio.tex
	pdflatex -interaction=nonstopmode -halt-on-error -output-directory=$(BUILD_DIR) portfolio.tex

compress: build/portfolio.pdf
	-rm "Lucas Caetano possatti.zip"
	all_cpp=`find src -name "*.cpp"`
	all_in=`find src -name "sample*.in"`
	all_out=`find src -name "sample*.out"`
	cp build/portfolio.pdf .
	zip "Lucas Caetano possatti.zip" "portfolio.tex" "portfolio.pdf" $$all_cpp $$all_in $$all_out
	rm portfolio.pdf

clean:
	rm -r $(BUILD_DIR)
