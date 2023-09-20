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
EXECUTABLES = hello exercise_3 exercise_4 exercise_5 exercise_6 exercise_7 exercise_8 exercise_10 exercise_10_v2 exercise_11 exercise_12 exercise_14 exercise_9 exercise_9_v2 exercise_13-2 exercise_13-1 exercise_13-3 exercise_15

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
hello.o : hello.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

programmes.o : programmes.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise_3.o : exercise_3.c programmes.h
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise_4.o : exercise_4.c programmes.h
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise_5.o : exercise_5.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise_6.o : exercise_6.c programmes.h
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise_7.o : exercise_7.c programmes.h
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise_8.o : exercise_8.c programmes.h
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise_10.o : exercise_10.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise_10_v2.o : exercise_10_v2.c programmes.h
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise_11.o : exercise_11.c programmes.h
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<
		
exercise_12.o : exercise_12.c programmes.h
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise_14.o : exercise_14.c programmes.h
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise_9.o : exercise_9.c
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise_9_v2.o : exercise_9_v2.c programmes.h
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise_13-2.o : exercise_13-2.c programmes.h
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise_13-1.o : exercise_13-1.c programmes.h
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise_13-3.o : exercise_13-3.c programmes.h
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

exercise_15.o : exercise_15.c programmes.h
	@echo ""
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<
		
########################################################
# regles explicites de creation des executables

hello : hello.o 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise_3 : exercise_3.o programmes.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise_4 : exercise_4.o programmes.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise_5 : exercise_5.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise_6 : exercise_6.o programmes.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise_7 : exercise_7.o programmes.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise_8 : exercise_8.o programmes.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise_10 : exercise_10.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise_10_v2 : exercise_10_v2.o programmes.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise_11 : exercise_11.o programmes.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise_12 : exercise_12.o programmes.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise_14 : exercise_14.o programmes.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise_9 : exercise_9.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise_9_v2 : exercise_9_v2.o programmes.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise_13-2 : exercise_13-2.o programmes.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise_13-1 : exercise_13-1.o programmes.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise_13-3 : exercise_13-3.o programmes.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

exercise_15 : exercise_15.o programmes.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

# regle pour "nettoyer" le r�pertoire
clean:
	rm -fR $(EXECUTABLES) *.o 
