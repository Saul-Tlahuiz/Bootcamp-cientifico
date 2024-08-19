#=
vamos a programar la funcion seno 
para eso vamos a definir lo que vamos a estar utilizando
Primero tomaremos un numero que este dent
=#

function intervalo(x)
    if x >= -π && x <= π
        println("El numero $x esta dentro del intervalo [-π,π]")
    else
        println("El numero $x  no esta dentro del intervalo")
    end
end

function signo(x)
    if x > 0
        return 1
    else 
        return -1
    end
end

function seno(x)
    x_0 = x/1024
    y = x_0*x_0
    for i=1:10
        y = 4*y*(1-y)
    end
    resultado = y
    return resultado
end
function main()
    println("Introduce un numero entre el intervalo [-π,π] para calcular el seno")
    numero = parse(Float64,readline())
    evaluacion = intervalo(numero)
    seno_calculado = sqrt(seno(numero))*signo(numero)
    println("El seno del numero $numero es: $seno_calculado")
end
main()