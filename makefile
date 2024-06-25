pdf: setup
	pdflatex -halt-on-error -output-directory=out main.tex && pdflatex -halt-on-error -output-directory=out main.tex && pdflatex -halt-on-error -output-directory=out main.tex
	
setup:
	mkdir -p out

clean:
	rm -rf out
