set grid
set term png 
set output 'PSO_2.png'
set xlabel 'Generation'
set ylabel 'ackley output'
set title 'PSO(n=30,D=2,iteration=2000,run=30)'
set xrange[0:200]
set yrange[0:25]
set xtics 0,20
set ytics 0,1.5
plot 'output.txt' using 1:2 smooth bezier with lines linestyle 3 title 'pso'
