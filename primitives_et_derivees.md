# Primitives et Dérivées — BAC STI2D Physique-Mathématiques

Fiche de révision complète pour l'épreuve de Physique-Chimie & Mathématiques (coefficient 16).

---

## SECTION 1 — TABLEAU DES DÉRIVÉES

### 1.1 Fonctions de base

| Fonction f(x) | Dérivée f'(x) | Conditions |
|---|---|---|
| k (constante) | 0 | k réel |
| x | 1 | |
| x^n | n · x^(n-1) | n réel, n ≠ 0 |
| x² | 2x | |
| x³ | 3x² | |
| x^(1/2) = √x | 1 / (2√x) | x > 0 |
| x^(-1) = 1/x | -1/x² | x ≠ 0 |
| x^(-2) = 1/x² | -2/x³ | x ≠ 0 |

### 1.2 Fonctions exponentielle

| Fonction f(x) | Dérivée f'(x) | Conditions |
|---|---|---|
| e^x | e^x | |
| e^(ax) | a · e^(ax) | a réel |
| e^(ax+b) | a · e^(ax+b) | a, b réels |
| e^(-x) | -e^(-x) | |
| e^(-ax) | -a · e^(-ax) | a réel |
| e^(-t/τ) | -(1/τ) · e^(-t/τ) | τ > 0 |

### 1.3 Fonctions logarithme

| Fonction f(x) | Dérivée f'(x) | Conditions |
|---|---|---|
| ln(x) | 1/x | x > 0 |
| ln(ax) | 1/x | x > 0, a > 0 |
| ln(ax+b) | a / (ax+b) | ax+b > 0 |
| ln(x²) | 2/x | x ≠ 0 |
| log₁₀(x) | 1 / (x · ln(10)) ≈ 1 / (2,303 · x) | x > 0 |

### 1.4 Fonctions trigonométriques

| Fonction f(x) | Dérivée f'(x) | Conditions |
|---|---|---|
| sin(x) | cos(x) | x en radians |
| cos(x) | -sin(x) | x en radians |
| tan(x) | 1/cos²(x) = 1 + tan²(x) | x ≠ π/2 + kπ |
| sin(ax) | a · cos(ax) | |
| cos(ax) | -a · sin(ax) | |
| sin(ax+b) | a · cos(ax+b) | |
| cos(ax+b) | -a · sin(ax+b) | |
| sin(ωt+φ) | ω · cos(ωt+φ) | ω pulsation |
| cos(ωt+φ) | -ω · sin(ωt+φ) | ω pulsation |

### 1.5 Fonctions composées — Règle de la chaîne

Si g(x) = f(u(x)), alors g'(x) = u'(x) · f'(u(x))

| Fonction f(x) | Dérivée f'(x) | Conditions |
|---|---|---|
| [u(x)]^n | n · u'(x) · [u(x)]^(n-1) | n réel |
| √(u(x)) | u'(x) / (2√(u(x))) | u(x) > 0 |
| e^(u(x)) | u'(x) · e^(u(x)) | |
| ln(u(x)) | u'(x) / u(x) | u(x) > 0 |
| sin(u(x)) | u'(x) · cos(u(x)) | |
| cos(u(x)) | -u'(x) · sin(u(x)) | |

### 1.6 Opérations sur les fonctions

| Opération | Formule | Exemple |
|---|---|---|
| Somme | (u + v)' = u' + v' | (x² + sin x)' = 2x + cos x |
| Différence | (u - v)' = u' - v' | |
| Produit par constante | (k·u)' = k·u' | (5e^x)' = 5e^x |
| Produit | (u·v)' = u'v + uv' | |
| Quotient | (u/v)' = (u'v - uv') / v² | v(x) ≠ 0 |

---

## SECTION 2 — TABLEAU DES PRIMITIVES

> Toute primitive est définie à une constante C près.  
> On note F une primitive de f : F'(x) = f(x)

### 2.1 Fonctions de base

| Fonction f(x) | Primitive F(x) + C | Conditions |
|---|---|---|
| 0 | C | |
| k (constante) | k·x + C | |
| x | x²/2 + C | |
| x² | x³/3 + C | |
| x³ | x⁴/4 + C | |
| x^n (n ≠ -1) | x^(n+1) / (n+1) + C | n réel, n ≠ -1 |
| √x = x^(1/2) | (2/3)·x^(3/2) + C | x ≥ 0 |
| 1/x = x^(-1) | ln|x| + C | x ≠ 0 |
| 1/x² = x^(-2) | -1/x + C | x ≠ 0 |

### 2.2 Fonctions exponentielle

| Fonction f(x) | Primitive F(x) + C | Conditions |
|---|---|---|
| e^x | e^x + C | |
| e^(ax) | (1/a) · e^(ax) + C | a ≠ 0 |
| e^(ax+b) | (1/a) · e^(ax+b) + C | a ≠ 0 |
| e^(-x) | -e^(-x) + C | |
| e^(-ax) | -(1/a) · e^(-ax) + C | a ≠ 0 |
| e^(-t/τ) | -τ · e^(-t/τ) + C | τ ≠ 0 |

### 2.3 Fonctions logarithme

| Fonction f(x) | Primitive F(x) + C | Conditions |
|---|---|---|
| 1/x | ln|x| + C | x ≠ 0 |
| 1/(ax+b) | (1/a) · ln|ax+b| + C | a ≠ 0, ax+b ≠ 0 |
| ln(x) | x·ln(x) - x + C | x > 0 |

### 2.4 Fonctions trigonométriques

| Fonction f(x) | Primitive F(x) + C | Conditions |
|---|---|---|
| cos(x) | sin(x) + C | |
| sin(x) | -cos(x) + C | |
| cos(ax) | (1/a)·sin(ax) + C | a ≠ 0 |
| sin(ax) | -(1/a)·cos(ax) + C | a ≠ 0 |
| cos(ax+b) | (1/a)·sin(ax+b) + C | a ≠ 0 |
| sin(ax+b) | -(1/a)·cos(ax+b) + C | a ≠ 0 |
| cos(ωt+φ) | (1/ω)·sin(ωt+φ) + C | ω ≠ 0 |
| sin(ωt+φ) | -(1/ω)·cos(ωt+φ) + C | ω ≠ 0 |

### 2.5 Formes remarquables (u'/u et u'·e^u)

| Fonction f(x) | Primitive F(x) + C | Conditions |
|---|---|---|
| u'(x) / u(x) | ln|u(x)| + C | u(x) ≠ 0 |
| u'(x) · e^(u(x)) | e^(u(x)) + C | |
| u'(x) · [u(x)]^n | [u(x)]^(n+1) / (n+1) + C | n ≠ -1 |

---

## SECTION 3 — RÈGLES ET FORMULES UTILES

### 3.1 Règle de la chaîne (dérivée d'une composée)

```
Si h(x) = f(g(x)), alors h'(x) = g'(x) · f'(g(x))
```

Exemple : h(x) = e^(3x²+1)
- g(x) = 3x²+1, g'(x) = 6x
- f(u) = e^u, f'(u) = e^u
- h'(x) = 6x · e^(3x²+1)

---

### 3.2 Règle du produit

```
(u · v)' = u' · v + u · v'
```

Exemple : h(x) = x² · e^x
- u = x², u' = 2x
- v = e^x, v' = e^x
- h'(x) = 2x · e^x + x² · e^x = e^x(2x + x²) = x·e^x(x + 2)

---

### 3.3 Règle du quotient

```
(u/v)' = (u'·v - u·v') / v²
```

Exemple : h(x) = sin(x)/x
- u = sin(x), u' = cos(x)
- v = x, v' = 1
- h'(x) = (cos(x)·x - sin(x)·1) / x²

---

### 3.4 Linéarité de l'intégrale

```
∫ [a·f(x) + b·g(x)] dx = a·∫f(x)dx + b·∫g(x)dx
```

---

### 3.5 Intégrale définie

```
∫[a→b] f(x) dx = [F(x)] de a à b = F(b) - F(a)
```

- F est une primitive quelconque de f
- Le résultat est un nombre (pas une fonction)
- Si f ≥ 0 sur [a;b], l'intégrale représente l'aire sous la courbe

Exemple :
```
∫[0→2] (3x²) dx = [x³] de 0 à 2 = 2³ - 0³ = 8
```

---

### 3.6 Valeur moyenne d'une fonction sur [a ; b]

```
f_moy = (1/(b-a)) · ∫[a→b] f(x) dx
```

Application physique : valeur moyenne d'une tension sinusoïdale, puissance moyenne, etc.

Exemple : valeur moyenne de P(t) = 500·sin(πt/12) sur [0 ; 12]
```
P_moy = (1/12) · ∫[0→12] 500·sin(πt/12) dt
      = (1/12) · 500 · [-( 12/π)·cos(πt/12)] de 0 à 12
      = (500/12) · (12/π) · [cos(0) - cos(π)]
      = (500/π) · 2 ≈ 318 W
```

---

## SECTION 4 — CAS CONCRETS STI2D

Ces formes reviennent systématiquement dans les épreuves. À maîtriser absolument.

### 4.1 Tableau des situations physiques

| Contexte physique | Fonction | Dérivée ou Primitive |
|---|---|---|
| **Charge condensateur** | u(t) = E·(1 - e^(-t/τ)) | u'(t) = (E/τ)·e^(-t/τ) |
| **Décharge condensateur** | u(t) = U₀·e^(-t/τ) | u'(t) = -(U₀/τ)·e^(-t/τ) |
| **Circuit RL (montée courant)** | i(t) = I₀·(1 - e^(-Rt/L)) | i'(t) = (I₀R/L)·e^(-Rt/L) |
| **Refroidissement de Newton** | T(t) = T_ext + (T₀-T_ext)·e^(-t/τ) | T'(t) = -(T₀-T_ext)/τ · e^(-t/τ) |
| **Désintégration radioactive** | N(t) = N₀·e^(-λt) | N'(t) = -λN₀·e^(-λt) |
| **Onde sinusoïdale (tension)** | u(t) = A·cos(ωt + φ) | u'(t) = -Aω·sin(ωt + φ) |
| **Onde sinusoïdale (courant)** | i(t) = I_m·sin(ωt) | i'(t) = I_m·ω·cos(ωt) |
| **Puissance → énergie** | P(t) quelconque | W = ∫[t1→t2] P(t) dt |
| **Énergie condensateur** | W = ½·C·u² | dW/dt = C·u·(du/dt) = u·i |
| **Énergie bobine** | W = ½·L·i² | dW/dt = L·i·(di/dt) = u·i |

---

### 4.2 Équation différentielle du 1er ordre — Méthode complète

**Forme canonique :**
```
y'(t) + (1/τ)·y(t) = K/τ
```

**Résolution en 3 étapes :**

**Étape 1** — Solution homogène (second membre = 0) :
```
y' + (1/τ)·y = 0  →  y_H(t) = C·e^(-t/τ)
```

**Étape 2** — Solution particulière (constante) :
```
y_P = K  (car y'_P = 0 et (1/τ)·K = K/τ ✓)
```

**Étape 3** — Solution générale + condition initiale y(0) = y₀ :
```
y(t) = K + (y₀ - K)·e^(-t/τ)
```

**Dérivée de la solution :**
```
y'(t) = -(y₀ - K)/τ · e^(-t/τ) = (K - y₀)/τ · e^(-t/τ)
```

---

### 4.3 Primitives utiles pour les calculs d'énergie

| Intégrale à calculer | Résultat |
|---|---|
| ∫ e^(-t/τ) dt | -τ · e^(-t/τ) + C |
| ∫[0→∞] e^(-t/τ) dt | τ |
| ∫[0→T] cos²(ωt) dt | T/2  (si T = période complète) |
| ∫[0→T] sin²(ωt) dt | T/2  (si T = période complète) |
| ∫ u·e^(u) du | (u-1)·e^u + C |
| ∫[0→t] E·(1-e^(-t/τ)) dt | E·[t + τ·e^(-t/τ) - τ] + C |

---

### 4.4 Dérivées des fonctions-solutions en physique

| Situation | f(t) | f'(t) | Interprétation |
|---|---|---|---|
| Charge RC | E·(1-e^(-t/τ)) | (E/τ)·e^(-t/τ) | Courant i = C·u' = (E/R)·e^(-t/τ) |
| Décharge RC | U₀·e^(-t/τ) | -(U₀/τ)·e^(-t/τ) | Courant i = -(U₀/R)·e^(-t/τ) |
| Montée RL | (E/R)·(1-e^(-t/τ)) | (E/L)·e^(-t/τ) | Tension u_L = L·i' = E·e^(-t/τ) |
| Sinusoïde A·cos(ωt) | A·cos(ωt) | -Aω·sin(ωt) | Déphasage de -π/2 |
| Sinusoïde A·sin(ωt) | A·sin(ωt) | Aω·cos(ωt) | Déphasage de +π/2 |

---

### 4.5 Propriétés de e^(-t/τ) à retenir

```
Valeurs numériques clés :
  t = 0    →  e^0    = 1       (valeur initiale)
  t = τ    →  e^(-1) ≈ 0,368  (36,8% de la valeur initiale)
  t = 2τ   →  e^(-2) ≈ 0,135
  t = 3τ   →  e^(-3) ≈ 0,050
  t = 5τ   →  e^(-5) ≈ 0,007  (régime permanent atteint à 99,3%)
  t → +∞   →  0
```

Pour 1 - e^(-t/τ) (charge) :
```
  t = 0  →  0          (départ à 0)
  t = τ  →  0,632      (63,2% de la valeur finale)
  t = 5τ →  0,993      (99,3% : régime permanent)
```

---

## RÉCAPITULATIF RAPIDE — À MÉMORISER

| Fonction | Dérivée | Primitive |
|---|---|---|
| k | 0 | kx |
| x^n | n·x^(n-1) | x^(n+1)/(n+1) |
| e^x | e^x | e^x |
| e^(ax) | a·e^(ax) | (1/a)·e^(ax) |
| ln(x) | 1/x | x·ln(x) - x |
| 1/x | -1/x² | ln\|x\| |
| sin(x) | cos(x) | -cos(x) |
| cos(x) | -sin(x) | sin(x) |
| sin(ax) | a·cos(ax) | -(1/a)·cos(ax) |
| cos(ax) | -a·sin(ax) | (1/a)·sin(ax) |

> **Règle mnémotechnique pour e^(ax) :** diviser par a pour la primitive, multiplier par a pour la dérivée.

> **Règle mnémotechnique pour sin/cos :** dériver cos donne -sin (signe change) ; intégrer sin donne -cos (signe change).

---

*Fiche destinée à la préparation du BAC STI2D — Épreuve Physique-Chimie & Mathématiques (coeff. 16)*
