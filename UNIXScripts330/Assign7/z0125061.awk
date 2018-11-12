#Doug MacClure
#Assignment 7
#awk script
#CSCI330 

#before getting input from inputfile, print a header with the BEGIN pattern
BEGIN {

print "Sales Data for year 2012"
print "========================"

}

#we want to only consider lines with the number 2012 in the inputfile
/\<2012\>/ {

	#if a line contains "2012" as a "word," print the second field 
	#with a concatenated colon, followed by a space and the sum of
	#the 3rd, 4th, and 5th fields to show total sales for a given month
	#in 2012
	printf("%s: %-7.2f\n",$2, $3+$4+$5)
	
	#sum together all of the 3rd, 4th, and 5th fields to keep track of
	#total sales for 2012
	sum = sum+$3+$4+$5
	#keep track of how many records contain "2012"
 	count++


}

#once we have finished reading input file, print END pattern

END {

#print desired output, with sum being total sales for 2012, and count being
#number of records for 2012
print "========================"
print "volume for 2012 is:", sum
print count, "records processed"

}


