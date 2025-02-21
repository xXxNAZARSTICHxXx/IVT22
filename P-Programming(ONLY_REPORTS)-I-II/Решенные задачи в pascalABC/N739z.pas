program N739z;
var
a,e,sum,n,b:real;
c,d,g,f,k:integer;

procedure firstaction(var a:real);
var
x:integer;
begin
  readln(x);
  a:=x/3;
end;

procedure secondaction(var k:integer;var a,b:real);
begin
  b:=a*(4*k+2);
end;

procedure thirdaction(var c,d:integer;var  k:integer);
begin
  d:=-1;
  c:=k+1;
  if c mod 2 = 0 then
    d:=-d;
end;

procedure fourthaction(var g,f: integer;var  k:integer);
begin
  g:=2*k+1;
  f:=g*f;
end;

procedure fifthaction(var n,sum:real;var b:real;var d,f:integer);
begin
  n:=d/f*b;
  sum:=sum+n;
end;

procedure sixthaction(var sun:real);
begin
  writeln('Точность = ',sum);
end;


begin
  e:=0.000001;
  n:=1;
  k:=0;
  firstaction(a);
  while n>e do begin
    k:=k+1;
    secondaction(k,a,b);
    thirdaction(c,d,k);
    fourthaction(g,f,k);
    fifthaction(n,sum,b,d,f);
  end;
    sixthaction(sum);
end.