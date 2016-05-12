BUILD_DIR=build

build/portfolio.pdf: portfolio.tex
	mkdir $(BUILD_DIR) -p
	pdflatex -interaction=nonstopmode -halt-on-error -output-directory=$(BUILD_DIR) portfolio.tex
	pdflatex -interaction=nonstopmode -halt-on-error -output-directory=$(BUILD_DIR) portfolio.tex

clean:
	rm -r $(BUILD_DIR)
