

f = open("dijkstraData (1).txt","r");
g = open("dijkstraData_parsed.txt","w");
for lines in f:
  lines = lines.split();
	for te in lines[1:]:
		r = te.split(',');
		g.write(str(lines[0])+' '+str(r[0])+' '+str(r[1])+'\n');
f.close();
g.close();
