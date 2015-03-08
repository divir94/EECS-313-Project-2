# THIS IS JUST A PLACEHOLDER!  YOUR MODEL GOES HERE....

param avg = (sum{i in CLASSES} hours[i])/ (NumQuarters);

var x{i in CLASSES, j in QUARTERS} binary;
var y{i in CLASSES} >= 0;
var Z >= 0;

minimize objective: Z;

subject to quarter_deviation_1{j in QUARTERS}:
	Z >= (sum{i in CLASSES} x[i, j]*hours[i]) - avg;
subject to quarter_deviation_2{j in QUARTERS}:
	Z >= avg - (sum{i in CLASSES} x[i, j]*hours[i]);

subject to one_class_per_quarter{i in CLASSES}:
	sum{j in QUARTERS} x[i, j] = 1; 

subject to class_limit_in_quarter{j in QUARTERS}:
	sum{i in CLASSES} x[i, j] <= MaxClassesPerQuarter;

subject to prereq_1{(class_a, class_b) in PREREQS}:
	y[class_a]+1 <= y[class_b];

subject to prereq_2{i in CLASSES}:
	y[i] = sum{j in QUARTERS} (x[i,j]*j);

