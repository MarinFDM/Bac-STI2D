# FICHE DE COURS — PHYSIQUE-MATHÉMATIQUES BAC STI2D
## Terminale STI2D — Enseignement de spécialité

---

## 🎯 FORMAT DE L'ÉPREUVE

| Critère | Détail |
|---|---|
| **Coefficient** | **16** (l'une des épreuves les plus importantes du Bac) |
| **Durée écrite** | 3 heures |
| **Durée pratique** | 2 heures (à partir de 2026) |
| **Structure** | 4 exercices notés sur 20 (environ 4-5 pts chacun) |
| **Nature** | Problèmes contextualisés (éolienne, voiture électrique, etc.) |
| **Attendus** | Justifier chaque étape, vérifier les unités, interpréter |

> ⚠️ **Conseil clé** : Les questions sont progressives — ne pas bloquer sur une question, passer à la suite et revenir.

---

# ═══════════════════════════════════════
# PARTIE MATHÉMATIQUES
# ═══════════════════════════════════════

---

## 1. FONCTION EXPONENTIELLE

### 1.1 Définition et propriétés fondamentales

La **fonction exponentielle** est l'unique fonction telle que :

```
f'(x) = f(x)   et   f(0) = 1
```

On la note **e^x** ou **exp(x)**, où **e ≈ 2,718** (nombre d'Euler).

### 1.2 Propriétés algébriques

| Propriété | Formule |
|---|---|
| Produit | **e^(a+b) = e^a × e^b** |
| Quotient | **e^(a−b) = e^a / e^b** |
| Puissance | **(e^a)^n = e^(na)** |
| Inverse | **e^(−a) = 1/e^a** |
| Valeurs | e^0 = 1 ; e^1 = e ≈ 2,718 |

### 1.3 Dérivée

```
Si f(x) = e^(u(x))  alors  f'(x) = u'(x) · e^(u(x))
```

**Exemples :**
- f(x) = e^(3x) → f'(x) = 3·e^(3x)
- f(x) = e^(−x/τ) → f'(x) = (−1/τ)·e^(−x/τ)  ← très utilisé en physique !
- f(x) = 5·e^(2x+1) → f'(x) = 10·e^(2x+1)

### 1.4 Tableau de variation de e^x

| x | −∞ | → | 0 | → | +∞ |
|---|---|---|---|---|---|
| f'(x) = e^x | + | + | + | + | + |
| f(x) = e^x | ↗ | | 1 | | ↗ |

- Fonction **strictement croissante** sur ℝ
- Toujours **strictement positive** : e^x > 0 pour tout x

### 1.5 Limites

```
lim(x→+∞) e^x = +∞
lim(x→−∞) e^x = 0    (asymptote horizontale y = 0)
lim(x→+∞) e^x / x^n = +∞  (l'exponentielle "l'emporte" sur tout polynôme)
lim(x→−∞) x^n · e^x = 0   (l'exponentielle "l'emporte" sur tout polynôme)
```

### 1.6 Résolution d'équations exponentielles

```
e^f(x) = e^g(x)  ⟺  f(x) = g(x)
e^f(x) = k  ⟺  f(x) = ln(k)   (si k > 0)
```

**Exemple physique :** Circuit RC, la tension vaut u(t) = E(1 − e^(−t/τ))
- Quand atteint-on u = 0,63 E ? → 0,63 E = E(1 − e^(−t/τ)) → e^(−t/τ) = 0,37 → t = τ

> 📌 **Remarque importante** : En physique, on retrouve constamment la forme **A·e^(−t/τ)** (décharge d'un condensateur, refroidissement, décroissance radioactive). τ est la **constante de temps**.

---

## 2. LOGARITHME NÉPÉRIEN (ln)

### 2.1 Définition

Le **logarithme népérien** est la fonction réciproque de l'exponentielle :

```
ln(x) est défini pour x > 0
ln(e^x) = x   et   e^(ln x) = x
ln(1) = 0   ;   ln(e) = 1
```

### 2.2 Propriétés algébriques

| Propriété | Formule |
|---|---|
| Produit | **ln(a×b) = ln(a) + ln(b)** |
| Quotient | **ln(a/b) = ln(a) − ln(b)** |
| Puissance | **ln(a^n) = n·ln(a)** |
| Inverse | **ln(1/a) = −ln(a)** |
| Racine | **ln(√a) = ½·ln(a)** |

**Exemples :**
- ln(6) = ln(2×3) = ln(2) + ln(3)
- ln(e²) = 2
- ln(1/5) = −ln(5)

### 2.3 Dérivée

```
Si f(x) = ln(u(x))  alors  f'(x) = u'(x) / u(x)
```

**Exemples :**
- f(x) = ln(3x) → f'(x) = 3/(3x) = 1/x
- f(x) = ln(x²+1) → f'(x) = 2x/(x²+1)
- f(x) = ln(−x) → f'(x) = −1/(−x) = 1/x  (définie pour x < 0)

### 2.4 Tableau de variation de ln(x)

| x | 0⁺ | → | 1 | → | +∞ |
|---|---|---|---|---|---|
| f'(x) = 1/x | + | + | + | + | + |
| f(x) = ln(x) | −∞ ↗ | | 0 | | ↗ +∞ |

- Fonction **strictement croissante** sur ]0 ; +∞[
- Asymptote verticale en x = 0

### 2.5 Limites

```
lim(x→0⁺) ln(x) = −∞
lim(x→+∞) ln(x) = +∞  (mais croît très lentement)
lim(x→+∞) ln(x)/x = 0  (ln "perd" devant x)
lim(x→0⁺) x·ln(x) = 0
```

### 2.6 Résolution d'équations logarithmiques

```
ln(f(x)) = ln(g(x))  ⟺  f(x) = g(x)  (avec f(x) > 0 et g(x) > 0)
ln(f(x)) = k  ⟺  f(x) = e^k
```

**Exemple physique :** Niveau sonore L = 10·log₁₀(I/I₀)
- (Attention : c'est log base 10, pas ln ! Conversion : log₁₀(x) = ln(x)/ln(10))

> 📌 **Remarque** : ln est utilisé pour résoudre les équations du type e^(−t/τ) = 0,5 → −t/τ = ln(0,5) → t = −τ·ln(0,5) = τ·ln(2)

---

## 3. CALCUL INTÉGRAL

### 3.1 Primitives — Tableau de référence

| Fonction f(x) | Primitive F(x) |
|---|---|
| k (constante) | kx + C |
| x^n (n ≠ −1) | x^(n+1)/(n+1) + C |
| 1/x | ln\|x\| + C |
| e^x | e^x + C |
| e^(ax) | (1/a)·e^(ax) + C |
| cos(x) | sin(x) + C |
| sin(x) | −cos(x) + C |
| cos(ωx) | (1/ω)·sin(ωx) + C |
| sin(ωx) | −(1/ω)·cos(ωx) + C |

> ⚠️ **Règle importante** : Si F est une primitive de f, alors F + C est aussi une primitive (C ∈ ℝ quelconque).

### 3.2 Intégrale définie

```
∫[a→b] f(x) dx = [F(x)]_a^b = F(b) − F(a)
```

**Propriétés :**
```
∫[a→b] (f + g) dx = ∫[a→b] f dx + ∫[a→b] g dx
∫[a→b] k·f dx = k · ∫[a→b] f dx
∫[a→b] f dx = −∫[b→a] f dx
∫[a→c] f dx = ∫[a→b] f dx + ∫[b→c] f dx
```

**Exemple :** ∫[0→2] (3x² + 2x) dx = [x³ + x²]₀² = (8+4) − (0+0) = 12

### 3.3 Théorème fondamental du calcul intégral

Si F est une primitive de f sur [a,b], continue sur [a,b] :
```
∫[a→b] f(x) dx = F(b) − F(a)
```

### 3.4 Applications physiques

**Valeur moyenne** d'une fonction sur [a,b] :
```
f_moy = (1/(b−a)) · ∫[a→b] f(x) dx
```

**Énergie à partir de la puissance** :
```
W = ∫[t1→t2] P(t) dt    (en joules, si P en watts et t en secondes)
```

**Exemple :** P(t) = 100·e^(−t/5) W, énergie entre t=0 et t=10 s :
```
W = ∫[0→10] 100·e^(−t/5) dt = 100·[−5·e^(−t/5)]₀^10
  = 100·(−5·e^(−2) + 5·e^0) = 500·(1 − e^(−2)) ≈ 500 × 0,865 ≈ 432 J
```

> 📌 **Lien physique** : L'intégrale est l'outil mathématique pour calculer une **accumulation** (énergie = somme des puissances instantanées, charge = somme des courants, etc.)

---

## 4. ÉQUATIONS DIFFÉRENTIELLES DU 1er ORDRE

### 4.1 Forme générale

```
y'(t) + a·y(t) = b
```
où a et b sont des constantes réelles, a ≠ 0.

### 4.2 Résolution complète

**Étape 1 : Solution de l'équation homogène** (sans second membre)
```
y' + a·y = 0  →  y_H(t) = K·e^(−at)   (K ∈ ℝ)
```

**Étape 2 : Solution particulière** (constante, régime permanent)
```
y_P = b/a   (on cherche une solution constante y' = 0)
```

**Étape 3 : Solution générale**
```
y(t) = K·e^(−at) + b/a
```

**Étape 4 : Détermination de K par la condition initiale (CI)**
- Si y(0) = y₀ : K + b/a = y₀ → K = y₀ − b/a

### 4.3 Forme physique typique — Circuit RC

L'équation du circuit RC :
```
τ · (du/dt) + u = E
```
avec τ = RC (constante de temps), E = tension d'alimentation.

**Solution :**
```
u(t) = E + (u₀ − E)·e^(−t/τ)
```
où u₀ = u(0) = tension initiale.

**Cas particulier — charge (u₀ = 0) :**
```
u(t) = E·(1 − e^(−t/τ))
```

**Cas particulier — décharge (E = 0) :**
```
u(t) = u₀·e^(−t/τ)
```

### 4.4 Régime transitoire et régime permanent

| Terme | Rôle |
|---|---|
| **K·e^(−at)** | **Régime transitoire** : disparaît quand t→+∞ |
| **b/a** | **Régime permanent** : valeur finale atteinte |
| **τ = 1/a** | **Constante de temps** : durée caractéristique |

> 📌 **Règle pratique** : Le régime permanent est atteint après **5τ** (à 99,3%). À t = τ, la grandeur a atteint 63,2% de sa valeur finale (charge) ou perdu 63,2% (décharge).

### 4.5 Circuit RL

L'équation du circuit RL :
```
L · (di/dt) + R·i = E
```
avec τ = L/R (constante de temps du circuit RL).

**Solution :**
```
i(t) = (E/R)·(1 − e^(−t/τ))   (si i(0) = 0)
```

**Exemple numérique :** R = 100 Ω, L = 0,5 H, E = 12 V
- τ = L/R = 0,5/100 = 5 ms
- i(∞) = E/R = 12/100 = 0,12 A
- i(5ms) = 0,12·(1−e⁻¹) ≈ 0,076 A

---

## 5. ÉQUATIONS DIFFÉRENTIELLES DU 2e ORDRE

### 5.1 Forme générale — Oscillateur

```
y'' + (ω₀/Q)·y' + ω₀²·y = ω₀²·E
```
où :
- **ω₀** = pulsation propre (rad/s)
- **Q** = facteur de qualité (sans unité)
- **E** = valeur d'équilibre

Forme alternative avec coefficient d'amortissement **m** :
```
y'' + 2m·ω₀·y' + ω₀²·y = ω₀²·E
```

### 5.2 Nature des solutions (discriminant Δ)

L'équation caractéristique est : **r² + (ω₀/Q)·r + ω₀² = 0**

| Cas | Condition | Régime | Solution |
|---|---|---|---|
| **Sur-amorti** | Q < 1/2 (Δ > 0) | Apériodique | y(t) = A·e^(r₁t) + B·e^(r₂t) + E |
| **Critique** | Q = 1/2 (Δ = 0) | Critique | y(t) = (A + Bt)·e^(r·t) + E |
| **Sous-amorti** | Q > 1/2 (Δ < 0) | Pseudo-périodique | y(t) = e^(αt)·(A·cos(ωt) + B·sin(ωt)) + E |

### 5.3 Exemple — Oscillateur mécanique (masse-ressort)

```
m·x'' + f·x' + k·x = 0
```
- ω₀ = √(k/m) (pulsation propre)
- Q = m·ω₀/f (facteur de qualité)
- T₀ = 2π/ω₀ (période propre)

**Exemple numérique :** m = 1 kg, k = 100 N/m, f = 2 N·s/m
- ω₀ = √(100/1) = 10 rad/s
- T₀ = 2π/10 ≈ 0,63 s
- Q = 1×10/2 = 5 → Q > 0,5 → régime pseudo-périodique

> 📌 **Remarque** : En STI2D, on étudie surtout le cas **sous-amorti** (Q > 1/2) qui donne des oscillations amorties, et le régime **forcé** avec source sinusoïdale (résonance en tension).

---

## 6. NOMBRES COMPLEXES

### 6.1 Définition

```
Un nombre complexe z = a + ib
- a = Re(z) = partie réelle
- b = Im(z) = partie imaginaire
- i² = −1
```

### 6.2 Formes d'écriture

**Forme algébrique :**
```
z = a + ib
```

**Forme trigonométrique :**
```
z = r·(cos θ + i·sin θ)
```

**Forme exponentielle (notation d'Euler) :**
```
z = r·e^(iθ)
```

où :
```
r = |z| = √(a² + b²)   (module)
θ = arg(z) = arctan(b/a)  (argument, en radians)
```

### 6.3 Conjugué

```
z̄ = a − ib
|z|² = z·z̄ = a² + b²
```

### 6.4 Opérations

**Addition :** (a + ib) + (c + id) = (a+c) + i(b+d)

**Multiplication :** (a + ib)(c + id) = (ac−bd) + i(ad+bc)

**Division :**
```
z₁/z₂ = (z₁·z̄₂) / (z₂·z̄₂) = (z₁·z̄₂) / |z₂|²
```

**En forme exponentielle :**
```
z₁·z₂ = r₁r₂·e^(i(θ₁+θ₂))    →  modules se multiplient, arguments s'additionnent
z₁/z₂ = (r₁/r₂)·e^(i(θ₁−θ₂)) →  modules se divisent, arguments se soustraient
```

### 6.5 Formule d'Euler

```
e^(iθ) = cos θ + i·sin θ
e^(−iθ) = cos θ − i·sin θ
cos θ = (e^(iθ) + e^(−iθ)) / 2
sin θ = (e^(iθ) − e^(−iθ)) / (2i)
```

### 6.6 Application aux circuits en régime sinusoïdal (AC)

En régime sinusoïdal, on représente les grandeurs par des **phaseurs** (nombres complexes) :

```
u(t) = U_m·cos(ωt + φ) ↔ Ū = U_m·e^(iφ)
i(t) = I_m·cos(ωt + ψ) ↔ Ī = I_m·e^(iψ)
```

**Impédances complexes :**

| Composant | Impédance Z |
|---|---|
| Résistance R | **Z_R = R** |
| Condensateur C | **Z_C = 1/(jCω) = −j/(Cω)** |
| Bobine L | **Z_L = jLω** |

(Notation : j = i en électricité)

**Loi d'Ohm généralisée :**
```
Ū = Z̄ · Ī
```

**Exemple :** Circuit RC série, ω = 1000 rad/s, R = 1000 Ω, C = 1 µF
- Z_C = 1/(j×1000×10⁻⁶) = −j×1000 = −1000j Ω
- Z_tot = 1000 − 1000j
- |Z_tot| = √(1000² + 1000²) = 1000√2 ≈ 1414 Ω
- φ = arctan(−1000/1000) = −π/4 = −45°

> 📌 **Déphasage** : φ > 0 → courant en avance sur tension ; φ < 0 → courant en retard sur tension.

---

# ═══════════════════════════════════════
# PARTIE PHYSIQUE
# ═══════════════════════════════════════

---

## 1. ÉNERGIE ÉLECTRIQUE

### 1.1 Loi d'Ohm et grandeurs fondamentales

```
U = R·I     (tension en V, résistance en Ω, courant en A)
```

**Associations de résistances :**
```
Série :   R_eq = R₁ + R₂ + ... + Rₙ
Parallèle : 1/R_eq = 1/R₁ + 1/R₂ + ... + 1/Rₙ
```

### 1.2 Puissance électrique

```
P = U·I = R·I² = U²/R    (en watts W)
```

**Puissance dissipée par effet Joule :**
```
P_J = R·I²
```

### 1.3 Énergie électrique

```
W = P·t = U·I·t    (en joules J, ou kWh : 1 kWh = 3,6×10⁶ J)
```

### 1.4 Condensateur

Le condensateur stocke de l'énergie sous forme électrique.

**Relation courant-tension :**
```
i(t) = C · du/dt
```

**Énergie stockée :**
```
W_C = ½·C·U²    (en joules)
```

**Équation différentielle (circuit RC) :**
```
RC · du/dt + u = E   →   τ = RC  (constante de temps)
```

**Charge d'un condensateur (initialement déchargé) :**
```
u(t) = E·(1 − e^(−t/τ))
i(t) = (E/R)·e^(−t/τ)
```

**Décharge :**
```
u(t) = U₀·e^(−t/τ)
i(t) = −(U₀/R)·e^(−t/τ)
```

**Exemple :** R = 10 kΩ, C = 100 µF, E = 5 V
- τ = RC = 10×10³ × 100×10⁻⁶ = 1 s
- À t = 1 s : u(1) = 5(1 − e⁻¹) ≈ 3,16 V (63,2% de E)
- À t = 5 s : u(5) ≈ 5×0,993 ≈ 4,97 V (régime permanent ≈ atteint)

### 1.5 Bobine (inductance)

**Relation courant-tension :**
```
u(t) = L · di/dt
```

**Énergie stockée :**
```
W_L = ½·L·I²    (en joules)
```

**Équation différentielle (circuit RL) :**
```
L · di/dt + R·i = E   →   τ = L/R  (constante de temps)
```

### 1.6 Rendement énergétique

```
η = P_utile / P_absorbée = W_utile / W_absorbée    (sans unité, entre 0 et 1 ou %)
```

**Exemple :** Moteur : P_mécanique = 800 W, P_électrique = 1000 W → η = 0,80 = 80%

---

## 2. ÉNERGIE MÉCANIQUE

### 2.1 Travail d'une force

```
W = F·d·cos(α)    (en joules J)
```
- F : force (N), d : déplacement (m), α : angle entre F et déplacement
- Travail moteur si W > 0, travail résistant si W < 0

**Cas particuliers :**
- Force parallèle au déplacement : W = F·d
- Force perpendiculaire au déplacement : W = 0
- Force de pesanteur : W = mg(z_A − z_B) = −ΔEp

### 2.2 Puissance mécanique

```
P = F·v·cos(α) = F·v    (si F parallèle à v)    (en watts W)
```

**Exemples :**
- Voiture à v = 30 m/s, force motrice F = 2000 N → P = 60 000 W = 60 kW
- Puissance d'un couple : P = C·ω (C = couple en N·m, ω = vitesse angulaire en rad/s)

### 2.3 Énergie cinétique

```
Ec = ½·m·v²    (en joules J)
```

**Théorème travail-énergie cinétique :**
```
ΔEc = Ec_finale − Ec_initiale = ΣW_toutes_forces
```

**Exemple :** Voiture m = 1200 kg, v₁ = 0, v₂ = 20 m/s
- ΔEc = ½×1200×20² − 0 = 240 000 J = 240 kJ

### 2.4 Énergie potentielle de pesanteur

```
Ep = m·g·h    (en joules J, avec g = 9,81 m/s² ≈ 10 m/s²)
```
(h = altitude par rapport à un référentiel choisi)

### 2.5 Conservation de l'énergie mécanique

En **l'absence de frottements** :
```
Em = Ec + Ep = constante
```

Avec **frottements** (W_f = travail des frottements, négatif) :
```
Em_finale = Em_initiale + W_frottements
Ec_f + Ep_f = Ec_i + Ep_i + W_f
```

**Exemple :** Bille m = 0,1 kg tombe de h = 5 m (sans frottement)
- En haut : Em = Ep = mgh = 0,1×10×5 = 5 J, Ec = 0
- En bas : Em = 5 J = Ec = ½mv² → v = √(2×5/0,1) = 10 m/s

### 2.6 Rendement mécanique

```
η = P_utile / P_totale
```

**Rendement global de plusieurs éléments en cascade :**
```
η_global = η₁ × η₂ × η₃ × ...
```

---

## 3. THERMODYNAMIQUE

### 3.1 Température et chaleur

- Température en **Kelvin** : T(K) = T(°C) + 273
- **Chaleur** Q : énergie transférée thermiquement (en joules)
- Q > 0 : le système reçoit de la chaleur
- Q < 0 : le système perd de la chaleur

### 3.2 Capacité thermique massique

```
Q = m·c·ΔT    (en joules)
```
- m : masse (kg)
- c : capacité thermique massique (J·kg⁻¹·K⁻¹)
- ΔT = T_finale − T_initiale (en °C ou K, même valeur pour une différence)

**Valeurs importantes :**

| Matériau | c (J·kg⁻¹·K⁻¹) |
|---|---|
| Eau | **4 186 ≈ 4 200** |
| Aluminium | 900 |
| Fer | 450 |
| Cuivre | 385 |
| Béton | 840 |
| Air | 1 005 |

### 3.3 Puissance thermique

```
P_th = Q / t = m·c·ΔT / t    (en watts W)
```

### 3.4 Bilan thermique

```
ΔU = Q + W   (1er principe thermodynamique)
```
Pour un solide ou liquide (travail nul) :
```
Q_reçu = m·c·ΔT
```

**Mélange de corps :** La chaleur perdue par le corps chaud = chaleur gagnée par le corps froid
```
Q_perdu + Q_reçu = 0
m₁·c₁·(T_f − T₁) + m₂·c₂·(T_f − T₂) = 0
```

### 3.5 Transferts thermiques

| Mode | Mécanisme | Formule |
|---|---|---|
| **Conduction** | Agitation moléculaire, corps solide | P = λ·S·ΔT/e |
| **Convection** | Mouvement de fluide | P = h·S·ΔT |
| **Rayonnement** | Ondes électromagnétiques | P = ε·σ·S·T⁴ |

(λ = conductivité thermique W·m⁻¹·K⁻¹, e = épaisseur, h = coeff. convection, σ = 5,67×10⁻⁸ W·m⁻²·K⁻⁴)

### 3.6 Résistance thermique

```
R_th = e/(λ·S)    (en K/W)
Φ = ΔT / R_th    (flux thermique en W)
```

**En série :** R_th_totale = R_th1 + R_th2 + ...

---

## 4. ONDES MÉCANIQUES ET SONORES

### 4.1 Caractéristiques d'une onde

```
v = λ·f = λ/T
```
- v : célérité / vitesse de propagation (m/s)
- λ : longueur d'onde (m)
- f : fréquence (Hz = s⁻¹)
- T = 1/f : période (s)

**Onde progressive harmonique :**
```
y(x,t) = A·cos(ωt − kx + φ₀)
```
avec ω = 2πf (pulsation) et k = 2π/λ (nombre d'onde)

### 4.2 Ondes sonores

| Grandeur | Valeur |
|---|---|
| Vitesse dans l'air | **v = 340 m/s** (à 20°C) |
| Fréquences audibles | 20 Hz à 20 000 Hz |
| Ultrasons | f > 20 kHz |
| Infrasons | f < 20 Hz |

**Exemple :** f = 440 Hz (La musical) → λ = v/f = 340/440 ≈ 0,77 m

### 4.3 Niveau sonore (décibels)

```
L = 10 · log₁₀(I / I₀)    (en décibels dB)
```
où :
- I : intensité sonore (W/m²)
- I₀ = 10⁻¹² W/m² (seuil d'audibilité)

**Repères :**

| Son | Niveau L (dB) |
|---|---|
| Seuil d'audibilité | 0 dB |
| Chuchotement | 30 dB |
| Conversation | 60 dB |
| Circulation | 80 dB |
| Concert rock | 110 dB |
| Seuil douleur | 120 dB |

**Propriété importante :**
```
ΔL = 10 dB  ↔  I multiplié par 10
ΔL = 3 dB   ↔  I multiplié par 2 (approximation)
```

**Calcul inverse :**
```
I = I₀ · 10^(L/10)
```

---

## 5. ONDES ÉLECTROMAGNÉTIQUES

### 5.1 Spectre électromagnétique

```
Ondes radio → Micro-ondes → Infrarouge → Visible → UV → Rayons X → Gamma
(grandes λ, faibles f)                                    (petites λ, grandes f)
```

| Domaine | Longueur d'onde λ |
|---|---|
| Ondes radio | > 1 mm |
| Micro-ondes | 1 mm − 1 m |
| Infrarouge | 700 nm − 1 mm |
| **Lumière visible** | **400 nm − 700 nm** |
| UV | 10 nm − 400 nm |
| Rayons X | 0,01 nm − 10 nm |
| Rayons γ | < 0,01 nm |

### 5.2 Relations fondamentales

**Dans le vide (ou l'air) :**
```
c = λ·f    avec c = 3×10⁸ m/s
```

**Énergie d'un photon :**
```
E = h·f = h·c/λ
```
où **h = 6,626×10⁻³⁴ J·s** (constante de Planck)

**Exemple :** Lumière verte λ = 500 nm = 500×10⁻⁹ m
- f = c/λ = 3×10⁸ / 500×10⁻⁹ = 6×10¹⁴ Hz
- E = hf = 6,626×10⁻³⁴ × 6×10¹⁴ = 3,98×10⁻¹⁹ J

### 5.3 Application photovoltaïque

**Rendement d'une cellule :**
```
η = P_élec / P_solaire_reçue = P_élec / (E_éclairement × S)
```
(E_éclairement en W/m², S = surface en m²)

---

## 6. CIRCUITS EN RÉGIME SINUSOÏDAL

### 6.1 Rappels — Grandeurs sinusoïdales

```
u(t) = U_m·cos(ωt + φ_u)
i(t) = I_m·cos(ωt + φ_i)
```
- U_m : amplitude (tension maximale)
- ω = 2πf : pulsation (rad/s)
- **Valeur efficace** : U = U_m/√2 et I = I_m/√2

### 6.2 Impédances (rappel)

```
Z_R = R              (résistance pure, déphasage nul)
Z_L = jLω            (bobine, courant en retard de π/2)
Z_C = 1/(jCω)        (condensateur, courant en avance de π/2)
```

**Circuit RLC série :**
```
Z = R + j(Lω − 1/(Cω))
|Z| = √(R² + (Lω − 1/(Cω))²)
```

### 6.3 Déphasage

```
tan(φ) = (Lω − 1/(Cω)) / R
```
- φ > 0 : circuit inductif (tension en avance sur courant)
- φ < 0 : circuit capacitif (tension en retard sur courant)

### 6.4 Résonance en intensité (circuit RLC série)

À la résonance : **Z_L = Z_C**, soit **Lω₀ = 1/(Cω₀)**

```
ω₀ = 1/√(LC)         (pulsation de résonance)
f₀ = 1/(2π√(LC))     (fréquence de résonance)
```

À la résonance : Z = R (minimum), I = U/R (maximum), déphasage = 0.

### 6.5 Filtres

**Filtre passe-bas RC (sortie sur C) :**
```
H(f) = U_C/U_e = 1 / √(1 + (RC·ω)²)
Fréquence de coupure : f_c = 1/(2πRC)
```

**Filtre passe-haut RC (sortie sur R) :**
```
H(f) = U_R/U_e = RCω / √(1 + (RC·ω)²)
```

> 📌 À f = f_c : H = 1/√2 ≈ 0,707 → atténuation de −3 dB

---

## 7. CHIMIE : COMBUSTION, OXYDORÉDUCTION, ACIDO-BASIQUE

### 7.1 Combustion

**Combustion complète d'un hydrocarbure :**
```
CₓHᵧ + (x + y/4)·O₂ → x·CO₂ + (y/2)·H₂O
```

**Exemple :** Méthane CH₄ :
```
CH₄ + 2O₂ → CO₂ + 2H₂O
```
- Combustion complète : CO₂ et H₂O
- Combustion incomplète : CO et suies en plus

### 7.2 Oxydoréduction

**Oxydation** : perte d'électrons (nombre d'oxydation augmente)
**Réduction** : gain d'électrons (nombre d'oxydation diminue)

```
Oxydant + n·e⁻ → Réducteur    (demi-équation de réduction)
Réducteur → Oxydant + n·e⁻    (demi-équation d'oxydation)
```

**Pile électrochimique :**
```
FEM = E_cathode − E_anode    (en volts)
```

### 7.3 pH et acido-basique

**Définition du pH :**
```
pH = −log[H₃O⁺]
[H₃O⁺] = 10^(−pH)
```

**Eau :** pH = 7 (neutre), [H₃O⁺] = [HO⁻] = 10⁻⁷ mol/L

| pH | Milieu |
|---|---|
| < 7 | Acide |
| = 7 | Neutre |
| > 7 | Basique |

**Acide fort HA :** [H₃O⁺] = C_a → pH = −log(C_a)

**Base forte BOH :** [HO⁻] = C_b → pH = 14 + log(C_b)

**Exemple :** Solution HCl à C = 0,01 mol/L → pH = −log(0,01) = 2

---

# ═══════════════════════════════════════
# FORMULES ESSENTIELLES — RÉCAPITULATIF
# ═══════════════════════════════════════

## Mathématiques

| Formule | Signification |
|---|---|
| **(e^a)' = a·e^a** | Dérivée de l'exponentielle |
| **(ln u)' = u'/u** | Dérivée du logarithme |
| **∫e^(ax)dx = (1/a)e^(ax) + C** | Primitive de l'exponentielle |
| **y' + ay = b → y = K·e^(−at) + b/a** | Éq. diff. 1er ordre |
| **ω₀ = 1/√(LC)** | Pulsation propre oscillateur LC |
| **\|z\| = √(a²+b²)** | Module d'un complexe |

## Physique

| Formule | Signification |
|---|---|
| **W = U·I·t** | Énergie électrique |
| **τ = RC ou τ = L/R** | Constante de temps |
| **u(t) = E(1−e^(−t/τ))** | Charge condensateur |
| **Ec = ½mv²** | Énergie cinétique |
| **Ep = mgh** | Énergie potentielle |
| **Q = mcΔT** | Échange de chaleur |
| **v = λf** | Relation onde |
| **c = 3×10⁸ m/s** | Vitesse lumière |
| **E = hf** | Énergie photon |
| **L = 10·log(I/I₀)** | Niveau sonore (dB) |

---

*Fiche réalisée pour la préparation au BAC STI2D — Épreuve Physique-Mathématiques (coeff. 16)*
