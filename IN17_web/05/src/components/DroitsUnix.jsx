import { useState, useEffect } from 'react'

function DroitsUnix() {
  const [codeNumerique, setCodeNumerique] = useState(0)
  const [rwx, setRwx] = useState({
    r: false,
    w: false,
    x: false
  })

  useEffect(() => {
    // Met à jour le code numérique quand rwx change
    let code = 0
    if (rwx.r) code += 4
    if (rwx.w) code += 2
    if (rwx.x) code += 1
    setCodeNumerique(code)
  }, [rwx])

  const handleChange = (e) => {
    const { name, checked } = e.target
    setRwx(prev => ({
      ...prev,
      [name]: checked
    }))
  }

  return (
    <div className="droits-unix">
      <h2>Droits Unix</h2>
      <div className="checkbox-group">
        <label>
          <input
            type="checkbox"
            name="r"
            checked={rwx.r}
            onChange={handleChange}
          />
          Read (4)
        </label>
        <label>
          <input
            type="checkbox"
            name="w"
            checked={rwx.w}
            onChange={handleChange}
          />
          Write (2)
        </label>
        <label>
          <input
            type="checkbox"
            name="x"
            checked={rwx.x}
            onChange={handleChange}
          />
          Execute (1)
        </label>
      </div>
      <p>Code numérique : {codeNumerique}</p>
      <p>RWX : {JSON.stringify(rwx)}</p>
    </div>
  )
}

export default DroitsUnix
