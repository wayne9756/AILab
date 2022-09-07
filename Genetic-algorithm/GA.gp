set grid
set term png 
set output 'GA2.png'
set xlabel 'Generation'
set ylabel 'Fitness'
set title 'GA(n=20,bit=500,iteration=1000,run=100)'
set xrange[0:1000]
set yrange[0:500]
set xtics 0,100
set ytics 0,50
plot 'output.txt' using 1:2 smooth bezier with lines linestyle 3 title 'GA'
