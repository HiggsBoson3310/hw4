Resultados_hw4.pdf:Resultados_hw4.tex
	pdflatex Resultados_hw4.tex
Resultados_hw4.tex:surface_plot%.png
	pdflatex Resultados_hw4.tex
surface_plot%.png:Plots_Temperatura.py
	python Plots_Temperatura.py
Plots_Temperatura.py:DifusionTemperatura.x
	./DifusionTemperatura.x
DifusionTemperatura.x:DifusionTemperatura.c
	cc DifusionTemperatura.c -o DifusionTemperatura.x