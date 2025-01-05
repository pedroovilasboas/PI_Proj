# Nome do ficheiro principal LaTeX (sem extensão)
TARGET = Relatorio

# Comandos
PDFLATEX = pdflatex
RM = del

# Flags para o pdflatex
FLAGS = -interaction=nonstopmode -shell-escape

# Regra padrão
all: $(TARGET).pdf

# Compilar o documento PDF
$(TARGET).pdf: $(TARGET).tex
	$(PDFLATEX) $(FLAGS) $(TARGET).tex
	$(PDFLATEX) $(FLAGS) $(TARGET).tex

# Limpar ficheiros temporários
clean:
	$(RM) *.aux *.log *.out *.toc *.lof *.lot *.bbl *.blg *.nav *.snm *.vrb *.fls *.fdb_latexmk *.synctex.gz

# Limpar tudo, incluindo o PDF
cleanall: clean
	$(RM) $(TARGET).pdf

# Regra para recompilar tudo
rebuild: cleanall all
