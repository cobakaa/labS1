set terminal png size 640,640

set output 'plot.png'
set xrange[-11:30]
set yrange[-30:30]

plot "data.txt" using 1:2 with lines, "ab" with lines, "bc" with lines, "ac" with lines
