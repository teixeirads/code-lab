def soma(a, b):
    return a + b

def subtrai(a, b):
    return a - b

def multiplica(a, b):
    return a * b

def divide(a, b):
    if b == 0:
        return "Erro: Divisão por zero!"
    return a / b

def menu():
    print("\n--- Calculadora Python ---")
    print("1. Soma")
    print("2. Subtração")
    print("3. Multiplicação")
    print("4. Divisão")
    print("5. Sair")
    return input("Escolha uma opção: ")

def main():
    while True:
        opcao = menu()

        if opcao == '5':
            print(" calculadora encerrada!")
            break

        if opcao in ('1', '2', '3', '4'):
            try:
                num1 = float(input("Digite o primeiro número: "))
                num2 = float(input("Digite o segundo número: "))

                if opcao == '1':
                    print(f"Resultado: {num1} + {num2} = {soma(num1, num2)}")
                elif opcao == '2':
                    print(f"Resultado: {num1} - {num2} = {subtrai(num1, num2)}")
                elif opcao == '3':
                    print(f"Resultado: {num1} * {num2} = {multiplica(num1, num2)}")
                elif opcao == '4':
                    resultado = divide(num1, num2)
                    if isinstance(resultado, str):
                        print(resultado)
                    else:
                        print(f"Resultado: {num1} / {num2} = {resultado}")
            except ValueError:
                print("Erro: Por favor, digite números válidos.")
        else:
            print("Opção inválida! Tente novamente.")

if __name__ == "__main__":
    main()
