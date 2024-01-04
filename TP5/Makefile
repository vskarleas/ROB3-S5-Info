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
EXECUTABLES = exercise7 exercise7_v3 exercise1 exercise2 exercise3 exercise4 exercise5 exercise6 cours_5-35 cours_5-24 cours_5-18 cours_5-13 cours_5-15-16 cours_5-47 cours_5-50 cours_5-52a cours_5-52b

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

exercise4.o : exercise4.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise7.o : exercise7.c exercise7.h
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise6.o : exercise6.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise7_v3.o : exercise7_v3.c exercise7_v3.h
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise1.o : exercise1.c
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

exercise5.o : exercise5.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

cours_5-35.o : cours_5-35.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

cours_5-24.o : cours_5-24.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

cours_5-18.o : cours_5-18.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

cours_5-15-16.o : cours_5-15-16.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

cours_5-13.o : cours_5-13.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

cours_5-47.o : cours_5-47.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<\
	
cours_5-50.o : cours_5-50.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

cours_5-52a.o : cours_5-52a.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

cours_5-52b.o : cours_5-52b.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<
		
########################################################
# regles explicites de creation des executables

exercise4 : exercise4.o
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

exercise7_v3 : exercise7_v3.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise1 : exercise1.o
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

exercise6 : exercise6.o
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

cours_5-35 : cours_5-35.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

cours_5-24 : cours_5-24.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

cours_5-18 : cours_5-18.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

cours_5-15-16 : cours_5-15-16.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

cours_5-13 : cours_5-13.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

cours_5-47 : cours_5-47.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

cours_5-50 : cours_5-50.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

cours_5-52a : cours_5-52a.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

cours_5-52b : cours_5-52b.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

# regle pour "nettoyer" le r�pertoire
clean:
	rm -fR $(EXECUTABLES) *.o 
