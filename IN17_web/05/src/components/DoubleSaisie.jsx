import { useState, useRef } from 'react'

function DoubleSaisie() {
  const [compteur, setCompteur] = useState(0)
  const chaine1Ref = useRef('')
  const chaine2Ref = useRef('')

  const handleChange = (e) => {
    const { name, value } = e.target
    if (name === 'chaine1') {
      chaine1Ref.current = value
    } else {
      chaine2Ref.current = value
    }
  }

  const handleClick = () => {
    const newCount = compteur + 1
    setCompteur(newCount)
    console.log(`Compteur: ${newCount}, Première chaîne : ${chaine1Ref.current} et deuxième chaîne : ${chaine2Ref.current}`)
  }

  return (
    <div className="double-saisie">
      <input
        type="text"
        name="chaine1"
        onChange={handleChange}
        placeholder="Première chaîne"
      />
      <input
        type="text"
        name="chaine2"
        onChange={handleChange}
        placeholder="Deuxième chaîne"
      />
      <button onClick={handleClick}>Incrémenter et afficher</button>
    </div>
  )
}

export default DoubleSaisie
