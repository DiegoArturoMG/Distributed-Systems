import math

i=1
Max=10000000;
seno=0
coseno=0
tangente=0
logaritmo=0
raizCuad=0
while i < Max:
	seno += math.sin(i)
	coseno += math.cos(i)
	tangente += math.tan(i)
	if i > 0:
		logaritmo += math.log(i)
	raizCuad += math.sqrt(i)
	i += 1
