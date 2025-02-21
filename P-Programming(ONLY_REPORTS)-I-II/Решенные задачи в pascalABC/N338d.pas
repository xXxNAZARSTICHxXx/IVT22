program N338d;
Const m=25; //размерность массива A и B
      l=50;  
type
amassive=array[1..m] of integer; //создание собственных типов размерности массивов A и B
bmassive=array[1..l] of integer;
var
    n:byte; //ограничитель массива
    a:amassive; //массивы с разными предназначениями
    b:bmassive;
    
    
    procedure foolcheck(var n:byte); //проверка на дурака
    begin
    repeat 
    write('Введите размерность массива B, которое не должно превышать 50: ');
    readln(n);
    until n<51;
    end;
    
    procedure fulla(var a:amassive; m:byte); //ввод массива А разнообразными числами
    var
    i:byte;
    extra:integer;
    begin
      randomize; //введение рандома
      i:=1;
      while i<=(m) do begin
      extra:=random(50);
      if not(extra in a) then begin
        a[i]:=extra;
        writeln('A_',i,'=',a[i]);
        i:=i+1;
        end;
        end;
    writeln('------------');
    end;
    
    procedure fullb(var b:bmassive; var n:byte); //ввод массива В разнообразными числами
    var
    i:byte;
    extra:integer;
    begin
      i:=1;
    while i<=(n) do begin
      extra:=random(50);
      if not(extra in b) then begin
        b[i]:=extra;
        writeln('B_',i,'=',b[i]);
        i:=i+1; 
        end;
        end;
    writeln('------------');
    end;
    
    procedure doublecheck(a:amassive; b:bmassive; n,m:byte); //проверка и вывод результата по условию задачи
    var
    i,y:byte;
    t:boolean;
    Begin
    y:=0;
    t:=false;
    if m<=l then
      For i:=1 to n do 
        if (b[i] in a) then
          y:=y+1;
    if y=n then
      t:=true;
    writeln(t,', совпадений ',y,'/',n);
    end;

begin
  foolcheck(n); //включение всех процедур
  fulla(a,m);
  fullb(b,n);
  doublecheck(a,b,n,m);
End.