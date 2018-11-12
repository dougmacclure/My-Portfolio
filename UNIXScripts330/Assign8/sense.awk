NF > 1 {
name[$1] = $2
}
NF < 2 {
split($0,fields,"/")
sum[fields[2]] += fields[3]
count[fields[2]]++
}
END {
for (i in sum) {
printf("%15s %7.2f\n", name[i], 
sum[i]/count[i]) | "sort -nr -k 2"
}
}