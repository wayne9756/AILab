set grid
set term png 
set output 'GA.png'
set xlabel 'Generation'
set ylabel 'Fitness'
set title 'GA(n=20,bit=250,iteration=500,run=100)'
set xrange[0:500]
set yrange[0:250]
set xtics 0,50
set ytics 0,25
plot 'output.txt' using 1:2 smooth bezier with lines linestyle 3 title 'GA'
