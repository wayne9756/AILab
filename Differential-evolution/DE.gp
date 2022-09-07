set grid
set term png 
set output 'DE_2.png'
set xlabel 'iteration'
set ylabel 'ackley output'
set title 'DE(n=10,D=2,iteration=D*10000,run=30)'
set xrange[0:20000]
set yrange[0:25]
set xtics 0,2000
set ytics 0,1.5
plot 'output.txt' using 1:2 smooth bezier with lines linestyle 3 title 'de'
