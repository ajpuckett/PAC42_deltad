paper: main_Deltaq.tex
	pdflatex main_Deltaq.tex
	bibtex main_Deltaq
	pdflatex main_Deltaq.tex
	pdflatex main_Deltaq.tex

view: main_Deltaq
	evince main_Deltaq.pdf

clean:
	rm *{aux,out,pdf,toc,~}
