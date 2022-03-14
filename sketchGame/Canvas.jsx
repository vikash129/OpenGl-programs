import React, { useRef, useEffect } from 'react'

const Canvas = (props) => {

    const { draw } = props

    const canvasRef = useRef(null)

    useEffect(() => {
        const canvas = canvasRef.current  //<canvas width="600" height="600"></canvas>

        const ctx = canvas.getctx('2d')
      
        // const draw = ctx => {
        //     ctx.fillStyle = '#000000'
        //     ctx.beginPath()
        //     ctx.arc(50, 100, 20, 0, 2 * Math.PI)
        //     ctx.fill()
        // }

        //Our first draw
        ctx.fillStyle = '#000000'
        ctx.fillRect(0, 0, ctx.canvas.width, ctx.canvas.height)

    }, [])

    return (
       
        <canvas ref={canvasRef} {...props}/>
    )

}

export default Canvas

// const render = () => {
//     frameCount++
//     draw(ctx, frameCount)
//     animationFrameId = window.requestAnimationFrame(render)
//   }
//   render()
  
//   return () => {
//     window.cancelAnimationFrame(animationFrameId)
//   }
// }, [draw])