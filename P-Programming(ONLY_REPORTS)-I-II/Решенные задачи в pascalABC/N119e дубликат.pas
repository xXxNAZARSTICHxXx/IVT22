program N119e; //начало программы
var i:integer; x,e,sum:real;  //декларативная часть
 Logic: boolean;  //декларативная часть
  Question: Char;  //декларативная часть
  Way: string;  //декларативная часть
  YourFile: text;  //декларативная часть
begin //начало исполнительной части
  Logic:=false;
  writeln('Напиши адрес для создания отчета:');
  Readln(way);
  Assign(YourFile, Way);
  if FileExists(Way)= False then Rewrite(YourFile) else Append(YourFile);
  while logic = false do begin

    repeat //цикл - защита от ДУРАКА
    sum:=0; //обнуляем сумматор
    write('Введите точность e (желательно мелкое - 0.001, главное, чтобы оно было >0 или <1): '); //*дружественный интерфейс*
    readln(e); //ввод e
    until(e>0)and(e<1); //цикл - защита от ДУРАКА
    x:=1/(4**i+5**(i+2)); //выполняем первый шаг исходя из блок схем
    i:=i+1; //выполняем первый шаг исходя из блок схем
    sum:=sum+x; //выполняем первый шаг исходя из блок схем
    while abs(x)>e do begin // цикл while
     x:=1/(4**i+5**(i+2)); // выполняем пример по условию,записывая его в x
     i:=i+1; // продвигаем while, чтобы не получился бесконечный цикл
     sum:=sum+x; // добавляем ответ к сумматору
    end; // конец исполнительной части цикла

writeln(Yourfile, 'Результатом этого выражения является = ',sum:0:6); // *дружественный интерфейс*
Writeln('Хотите использовать программу еще раз? Y\N');
    Read(Question);
    If question = 'N' then Logic:= True;
  end;
  closefile(YourFile);
end. // конец программы