set grid
set term png 
set output 'tsp.png'
set xlabel 'x'
set ylabel 'y'
set title 'tsp with 2-opt'
set xrange[0:70]
set yrange[0:80]
set xtics 0,10
set ytics 0,10
plot "output.txt" with linespoints 
#plot 'output.txt' using 1:2 smooth bezier with linespoints title 'tsp' 
#plot "output.txt" every :::0::1 with lp, "" every :::2::2 with points

