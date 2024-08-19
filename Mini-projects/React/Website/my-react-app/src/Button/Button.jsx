// import styles from './Button.module.css';

function Button(){

    // Inline CSS

    const styles = {
        button: {
            backgroundColor: 'red',
            color: 'white',
            padding: '10px 20px',
            border: 'none',
            borderRadius: '5px',
            cursor: 'pointer'
        }
    }
    // MODULE METHOD CSS
    // return (<button className={styles.button}>Click me</button>);

    // INLINE METHOD CSS
    return (<button style={styles.button}>Click me</button>);
}

export default Button;