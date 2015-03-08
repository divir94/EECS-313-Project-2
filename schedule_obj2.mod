#########################################################################

# PREAMBLE: Here we define sets and parameters

# Number of quarters
param NumQuarters;

# Set of quarters (simply numbered from 1 to NumQuarters)
set QUARTERS := {1..NumQuarters};

# Number of classes per quarter
param MaxClassesPerQuarter;

# Set of classes
set CLASSES default {1 .. NumQuarters*MaxClassesPerQuarter};

# Number of hours per week for each class
param hours{i in CLASSES} >= 0;


# Set of prerequisites:
#
# Elements of this set have the form (i,j) where i and j are elements
# from CLASSES.  A prerequisite (i,j) means that class i has to be
# taken before class j
# 
set PREREQS within {i in CLASSES, j in CLASSES};

#########################################################################

# MODEL: Here we define variables, objective, and constraints

# Usually, you would write your model here, but because want to have the same
# model work with another preamble (schedule_random.mod), we
# include the model from a different file:

include obj2_model.inc

