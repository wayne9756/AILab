set grid
set term png 
set output 'tsp2.png'
set xlabel 'x'
set ylabel 'y'
set title 'TSP with 2-opt(Distance:430.231)'
set xrange[0:70]
set yrange[0:80]
set xtics 0,10
set ytics 0,10
set colorsequence podo 
plot "output.txt" with linespoints linestyle 7 lw 3  title 'TSP' 
#plot 'output.txt' using 1:2 smooth bezier with linespoints title 'tsp' 
#plot "output.txt" every :::0::1 with lp, "" every :::2::2 with points

