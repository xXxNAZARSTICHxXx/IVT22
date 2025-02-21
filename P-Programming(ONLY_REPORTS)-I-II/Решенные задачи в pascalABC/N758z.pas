program N758z;
var
ab,b,sum:real; //ab,b - описаны в коде(см. ниже); sum - сумматор;
Logic: boolean; //выключатель кода
Question: Char; //Ответ на "выключатель" 
Way: string; //way - путь файла для записи
YourFile: text; //YourFile - вывод в файл


//ПЕРВЫЕ ЗНАЧЕНИЯ ПРИ K=1
procedure startpos(var b: real; var ab:real);
var
x:integer;
a,aa:real; 
begin
  //ВСЕ ЧТО ДО ЦИКЛА WHILE - ПЕРВЫЕ ЗНАЧЕНИЯ ПРИ K=1;
  write('Введите число x из условия задачи: ');
  readln(x); //ввод числа x
  a:=x/3; //1 степень x/3
  aa:=a*a; //2 степень x/3
  ab:=aa*aa; //4 степень x/3
  b:=aa*aa*aa; //6 степень x/3
end;

//ВЫЧИСЛЕНИЕ ТОЧНОСТИ
procedure accuracy (var b: real; var ab:real; var sum: real);
var
k,x,d,provcount:integer; //k - шаг факториала; x - вводимое число по условию; d - флажок (-1/1);
e,ecount:real;// e - лимит по условию задачи; ecount - выдающее значение примера;
f:longint; //факториал
begin
  provcount:=1;
  f:=6; //стартовый фаториал 3 (3!)
  sum:=0; //сумматор
  k:=2; //факториал n+1 
  d:=-1; //флажок (-1/1)
  e:=0.000001; //заданная точность 
  ecount:=1; //стремящаяся точность (присвоено 1, чтобы цикл while начал работу) 
  while abs(ecount)>e do begin //пока модуль стремящейся точности > заданной точности, делать 
    k:=k+2; //продвижение числа в множители факториала (при k=1 из задачи(из него 3!) получаем позицию 4, потом при k=2(при 5!) получаем позицию 6,при k=3(7!) получаем 8 и т.д... 
    d:=-d; //переключение флажка -1/1/-1/1/-1 и т.д.
    ecount:=(d/f)*b; //вычисление примера при всех значениях
    if (k=4) or (k=6) or (k=8) then begin
      writeln('Член последовательности ', provCount,': ', ecount:0:8);
      provCount:=provCount+1;
    end;
    sum:=sum+ecount; //суммирование значения
    f:=f*k*(k+1); //вычисление факториала при k=2;k=3...
    b:=b*ab; //изменение степени для x/3 (6+4=10;10+4=14;14+4=18;18+4=22;22+4=...)
  end;
end;
  
begin
  Logic:=false;
  writeln('Напиши адрес для создания отчета:');
  Read(way); //считывание адреса для записи файла
  Assign(YourFile, Way); //объявление пути файла
  if FileExists(Way)= False then Rewrite(YourFile) else Append(YourFile); //проверка на файл
  while logic = false do begin
    
    startpos(b,ab);
    accuracy(b, ab, sum);
    writeln('Ответ при заданной точности 0,000001: ', sum:0:6); //вывод результата
    writeln(YourFile, 'Ответ при заданной точности 0,000001: ', sum:0:6); //вывод результата в файл
    Writeln('Хотите использовать программу еще раз? Y\N'); 
    Read(Question); //считывает ответ при Y-выключатель включен, при N-выключатель выключен
    if question = 'N' then Logic:= True; //если выключатель выключен
  end;
  closefile(YourFile); //закрываем файл
end.
