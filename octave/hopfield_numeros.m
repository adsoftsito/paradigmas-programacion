clear, clc

x0 = [-1, -1, 1, -1, -1, -1, 1, 1, -1, -1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1];
  
%x0

% patron 1 (representa un numero, letra, simbolo)

%x1

x1=[-1, 1,1,1,-1,1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,1,1,-1 ,-1,1, -1, -1, -1,1, -1, -1, -1, -1,1,1,1,1,1, -1, -1, -1, -1, -1];
% patron 2 (representa un numero, letra, simbolo)
%x1

% x1'

x2=[1,-1,-1,1,-1,1,-1 , -1,1 , -1,1 ,-1,-1,1,-1,1,1,1,1,1 ,-1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1];

x0mul = x0(:) * x0(:)';
%x0mul

x1mul = x1(:) * x1(:)';
%x1mul

x2mul = x2(:) * x2(:)';

w1 = x0mul + x1mul + x2mul;
%w1

w = w1 - diag(diag(w1));
% w

%input ( valor a encontrar )
% encontrar x1

x = [-1, 1,1,1,-1,1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,1,1,-1 ,-1,1, -1, -1, -1,1, -1, -1, -1, -1,1,1,1,1,1, -1, -1, -1, -1, -1];

% mul  sum(w * x)

u0 = x;
c=1;
x

ulast = x;

while (1)
  
  u0 = u0 * w;
  u0
   
    % aplicar funcion de activacion thresold
 
   for i=1:1:40
      if u0(i) > 0
        u0(i) = 1;
      else
        u0(i) = -1;
     endif
   endfor

  %c
  %u0
  %ulast

  if (u0 == ulast)
      fprintf(' encontrado \n');
      u0
      ulast
      c 
     break;  
  endif
    
    c = c + 1;
    ulast = u0;
   
end