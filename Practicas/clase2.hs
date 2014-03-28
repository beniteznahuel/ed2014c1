data Sexo = Masculino | Femenino deriving (Show)

data Persona = MkPersona Int String Sexo deriving (Show) -- ( CONSTRUCTOR DE PERSONA )

-- MkPersona :: Int -> String -> Persona 

cumplirAños :: Persona -> Persona
cumplirAños (MkPersona e n s) = MkPersona (e+1) n s

cambiarNombre :: Persona -> String -> Persona
cambiarNombre ( MkPersona e _ s) n = MkPersona e n s

esEgresado :: Persona -> Bool
esEgresado (MkPersona e _ _) = e > 18

data Color = Rojo | Azul | Verde | Negro deriving (Show)
data Dir = Norte | Sur | Este | Oeste deriving (Show)
data Celda = MkCelda {
  azules :: Int,
  rojas :: Int,
  verdes :: Int,
  negras :: Int
} deriving (Show)
type Fila = [Celda]

filaDe3 :: Fila
filaDe3 = [(MkCelda 0 0 0 0), (MkCelda 0 0 0 0), (MkCelda 0 0 0 0)]

filaVacia :: Int -> Fila
filaVacia 0 = []
filaVacia n = (MkCelda 0 0 0 0) : (filaVacia (n-1))

ponerRoja :: Celda -> Celda
ponerRoja  (MkCelda a r v n) = MkCelda a (r+1) v n

ponerRojaEnCadaUna :: Fila -> Fila
ponerRojaEnCadaUna [] = []
ponerRojaEnCadaUna (x:xs) = ponerRoja x : ponerRojaEnCadaUna xs

ponerUnaRojaEnTodas :: Tablero -> Tablero


type Tablero = [Fila]

tableroDe :: Int -> Int -> Tablero
tableroDe 0 c = []
tableroDe f c = filaVacia c : tableroDe (f-1) c

bolitasEnCelda :: Celda -> Int
bolitasEnCelda c = azules c + rojas c + negras c + verdes c

bolitasEnFila :: Fila -> Int
bolitasEnFila [] = 0
bolitasEnFila (c:cs) = bolitasEnCelda c + bolitasEnFila cs

bolitasEnTablero :: Tablero -> Int
bolitasEnTablero [] = 0
bolitasEnTablero (f:fs) = bolitasEnFila f + bolitasEnTablero fs

unirTablero :: Tablero -> Tablero -> Tablero
unirTablero [] [] = []
unirTablero (x:xs) (y:ys) = (sumarFilas x y) : unirTablero xs ys

sumarFilas :: Fila -> Fila -> Fila
sumarFilas [] [] = []
sumarFilas (x:xs) (y:ys) = (sumarCeldas x y) : sumarFilas xs ys

sumarCeldas :: Celda -> Celda -> Celda
sumarCeldas c1 c2 = MkCelda (azules c1 + azules c2) (rojas c1 + rojas c2) (verdes c1 + verdes c2) (negras c1 + negras c2)

--dada una lista de tableros quiero el tablero con más bolitas

fromJust :: Maybe a -> a
fromJust (Just x) = x

tableroConMasBolitas :: [Tablero] -> Maybe Tablero
tableroConMasBolitas [] = Nothing
tableroConMasBolitas [x] = Just x
tableroConMasBolitas (x:xs) = maxTablero x (fromJust (tableroConMasBolitas xs))

maxTablero :: Tablero -> Tablero -> Maybe Tablero
maxTablero t1 t2 | bolitasEnTablero t1 > bolitasEnTablero t2 = Just t1
		 | otherwise = Just t2
