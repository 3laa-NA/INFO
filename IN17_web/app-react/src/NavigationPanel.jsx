import Login from './Login'
import Logout from './Logout'

function NavigationPanel({ login, logout, isConnected }) {
    return (
        <nav>
            {isConnected ? 
                <Logout onLogout={logout} /> : 
                <Login onLogin={login} />
            }
        </nav>
    )
}

export default NavigationPanel
