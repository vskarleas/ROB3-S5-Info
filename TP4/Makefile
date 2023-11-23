#############################################################################
# Fichier Makefile 
# UE Infomatics for Robotics - Polytech Sorbonne - 2023/2024
# Author: Vasileios Filippos Skarleas - All rights reserved.
#############################################################################
# utilisation des variables internes $@ $< $^ $*
# $@ : correspond au nom de la cible
# $< : correspond au nom de la premiere dependance
# $^ : correspond � toutes les d�pendances
# $* : correspond au nom du fichier sans extension 
#       (dans les regles generiques uniquement)
#############################################################################
# information sur la regle executee avec la commande @echo
# (une commande commancant par @ n'est pas affichee a l'ecran)
#############################################################################

# Chaque exercise ies identifie par un programme principale nomé comme exercise_xxx.c 
# Les programmes peuvent etre base sur d'autres fonctionctions definies aux different fichiers

#############################################################################
# definition des variables locales
#############################################################################

# compilateur C
CC = clang

# chemin d'acces aux librairies (interfaces)
INCDIR = .

# chemin d'acces aux librairies (binaires)
LIBDIR = .

# options pour l'�dition des liens
LDOPTS = -L$(LIBDIR) -lm

# options pour la recherche des fichiers .o et .h
INCLUDEOPTS = -I$(INCDIR)

# options de compilation
COMPILOPTS = -g -Wall $(INCLUDEOPTS)

# liste des executables
EXECUTABLES = exercise1 exercise2 exercise3 exercise4 exercise5 test exercise7 exercise6 exercise3_v2 test2

#############################################################################
# definition des regles
#############################################################################

########################################################
# la r�gle par d�faut
all : $(EXECUTABLES)

########################################################
# regle generique : 
#  remplace les regles de compilation separee de la forme
#	module.o : module.c module.h
#		$(CC) -c $(COMPILOPTS) module.c
%.o : %.c %.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module "$*
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

########################################################
# regles explicites de compilation separee de modules
# n'ayant pas de fichier .h ET/OU dependant d'autres modules

function-exo1.o : function-exo1.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

functions-exo4.o : functions-exo4.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

functions-exo6.o : functions-exo6.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise1.o : exercise1.c function-exo1.h
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise2.o : exercise2.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise3.o : exercise3.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise3_v2.o : exercise3_v2.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise4.o : exercise4.c functions-exo4.h
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise5.o : exercise5.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test.o : test.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise7.o : exercise7.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise6.o : exercise6.c functions-exo6.h
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test2.o : test2.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

		
########################################################
# regles explicites de creation des executables

exercise1 : exercise1.o function-exo1.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise2 : exercise2.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise3 : exercise3.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise3_v2 : exercise3_v2.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise4 : exercise4.o functions-exo4.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise5 : exercise5.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

hello : test.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise7 : exercise7.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise6 : exercise6.o functions-exo6.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test2 : test2.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@



# regle pour "nettoyer" le r�pertoire
clean:
	rm -fR $(EXECUTABLES) *.o 
